/* Automatic device node creation */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

char *my_class_name=NULL;
char *my_dev_name=NULL;	
unsigned int num_dev=0;

module_param(num_dev, uint, S_IRUGO );
module_param(my_dev_name, charp, S_IRUGO | S_IWUSR); 
module_param(my_class_name, charp, S_IRUGO | S_IWUSR); 


dev_t dev = 0;
static struct class *dev_class;
static struct device **cdevice;

static int __init my_mod_init(void)
{
	int ans,i,j=0, major, minor;
	char dev_string[10]={0};

	pr_info("Hello world from mod33!\n");
	if(my_class_name == NULL || my_dev_name==NULL || num_dev==0)
	{
		if(num_dev==0)
		{
			pr_err("Number of devices can't be zero\n");
		}
		pr_err("Parameters needed\n");
		return -1;
	}

	cdevice = (struct device **)kmalloc((sizeof(struct device *))*num_dev, GFP_KERNEL);
	if(cdevice==NULL)
	{
		pr_err("Kernel memory allocation failed\n");
		return -1;
	
	}

	ans = alloc_chrdev_region(&dev, 0, num_dev, my_class_name);
	if (ans<0)
	{
		pr_err("Error in major:minor allotment!\n");
		goto free_km;
	}
	pr_info("major:minor range of %d devices %d:%d allotted!\n", num_dev, MAJOR(dev),MINOR(dev));

	dev_class = class_create(THIS_MODULE, my_class_name);
	if (IS_ERR(dev_class))
	{
		pr_err("Could not create device class %s\n", my_class_name);
		goto r_class;
	}
	major = MAJOR(dev);
	for (i=0;i<num_dev;i++)
	{
		minor = i;
		dev = MKDEV(major, minor);
		sprintf(dev_string, "%s%d", my_dev_name, i);
		cdevice[i] = device_create(dev_class, NULL, dev, NULL, dev_string);
		if (IS_ERR(cdevice[i]))
		{
			pr_err("Could not create device %s\n", dev_string);
			goto r_device;
		}
	}
	pr_info("%d devices %s under class %s created with success\n", 
			i, my_dev_name, my_class_name);
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
	kfree(cdevice);
	return -1;
}

static void __exit my_mod_exit(void)
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
	kfree(cdevice);
	pr_info("Memory allocated for devices freed\n");
	pr_info("major:minor numbers freed up...\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Device node creation module!");
