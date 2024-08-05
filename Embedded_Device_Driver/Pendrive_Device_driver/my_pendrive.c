/*
	Automatic character device creation
*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>

unsigned int num_dev=0;
char *my_class=NULL;
char *my_device=NULL;

module_param(num_dev, uint, S_IRUGO );
module_param(my_device, charp, S_IRUGO );
module_param(my_class, charp, S_IRUGO );


MODULE_PARM_DESC(num_dev, "Unsigned Int variable declared for number of devices");
MODULE_PARM_DESC(my_device, "Char pointer variable declared for name of device");
MODULE_PARM_DESC(my_class, "Char pointer variable declared for name of class");


dev_t dev=0;
static struct class *dev_class;
static struct device **devices;

static int __init my_init(void)
{
	
	int ans,i,j=0, major, minor;
	char dev_string[15]={0};

	pr_info("Hello from pendrive device module!\n");
	if(my_class == NULL || my_device==NULL || num_dev==0)
	{
		if(num_dev==0)
		{
			pr_err("Number of devices can't be zero\n");
		}
		pr_err("Parameters Incomplete | my_class=<class name> my_device=<device name> num_dev=<number of device>\n");
		return -1;
	}

	devices = (struct device **)kmalloc((sizeof(struct device *))*num_dev, GFP_KERNEL);
	if(devices==NULL)
	{
		pr_err("Kernel memory allocation failed\n");
		return -1;
	
	}

	ans = alloc_chrdev_region(&dev, 0, num_dev, my_class);
	if (ans<0)
	{
		pr_err("Error in major:minor allotment!\n");
		goto free_km;
	}
	pr_info("major:minor range of %d devices %d:%d allotted!\n", num_dev, MAJOR(dev),MINOR(dev));

	dev_class = class_create(THIS_MODULE, my_class);
	if (IS_ERR(dev_class))
	{
		pr_err("Could not create device class %s\n", my_class);
		goto r_class;
	}
	major = MAJOR(dev);
	for (i=0;i<num_dev;i++)
	{
		minor = i;
		dev = MKDEV(major, minor);
		sprintf(dev_string, "%s%02d", my_device, i);
		devices[i] = device_create(dev_class, NULL, dev, NULL, dev_string);
		if (IS_ERR(devices[i]))
		{
			pr_err("Could not create device %s\n", dev_string);
			goto r_device;
		}
	}
	pr_info("%d devices %s under class %s created with success\n", 
			i, my_device, my_class);
	return 0;

r_device:
	for(j=0;j<i;j++)
	{
		minor=j;
		dev=MKDEV(major,minor);
		device_destroy(dev_class, dev);
	}
	class_destroy(dev_class);
r_class:
	minor=0;
	dev=MKDEV(major,minor);
	unregister_chrdev_region(dev, 1);
free_km:
	kfree(devices);
	return -1;
}

static void __exit my_exit(void)
{
	int i=0,major,minor;
	pr_info("Goodbye world from mod33!\n");
	major=MAJOR(dev);
	for(i=0;i<num_dev;i++)
	{
		minor=i;
		dev=MKDEV(major,minor);
		device_destroy(dev_class, dev);
	}
	class_destroy(dev_class);
	minor=0;
	dev=MKDEV(major,minor);
	unregister_chrdev_region(dev,num_dev);
	kfree(devices);
	pr_info("Memory allocated for devices freed\n");
	pr_info("major:minor numbers freed up...\n");
	return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD  Prasad Kulkarni <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Device creation module!");
