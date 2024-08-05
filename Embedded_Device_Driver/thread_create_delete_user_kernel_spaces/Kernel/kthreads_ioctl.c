/* IOCTL on char device */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/kthread.h>

#include "../my_ioctls.h"

#define MY_CLASS_NAME	"threads_cls"
#define MY_DEV_NAME	"threads_dev"

#define TIME_INTVL 1000


static unsigned int period=1000;
static char thread_name[] = "my_device_thread";
static int thread_check = 1;


dev_t dev = 0;
static struct class *dev_class;
static struct device *cdevice;
static struct cdev my_cdev;
static struct task_struct *thread;


// function prototypes
static int __init my_thread_init(void);
static int my_thread_open(struct inode *inode, struct file *file);
static long my_thread_ioctl(struct file *file, unsigned int cmd, unsigned long args);
static int my_thread_release(struct inode *inode, struct file *file);
static void __exit my_thread_exit(void);
int thread_func(void *pv);


// create a fops struct
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_thread_open,
	.unlocked_ioctl = my_thread_ioctl,
	.release = my_thread_release,
};


static int my_thread_open(struct inode *inode, struct file *file)
{
	pr_info("My open function %s called\n", __func__);
	return 0;
}

static long my_thread_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	switch(cmd)
	{
		case START_DEVICE:
			if(thread_check)
			{
				thread = kthread_run(thread_func, NULL, thread_name);
				if (thread){ pr_info("Thread %s created!\n", thread_name); thread_check=0; }
				else{ pr_err("Cannot create thread %s\n", thread_name); goto r_thread; }
			}
			else
				pr_info("Thread already created\n");
			break;
		case STOP_DEVICE:
			if(!thread_check)
				kthread_stop(thread);
			thread_check=1;
			
			pr_info("Kernel thread Stopped\n");
			break;
		default:
			pr_err("Undefined command!\n");
			break;
	}
	return 0;

r_thread:
device_destroy(dev_class, dev);
class_destroy(dev_class);
cdev_del(&my_cdev);
unregister_chrdev_region(dev, 1);

return -1;
}

static int my_thread_release(struct inode *inode, struct file *file)
{
	pr_info("My release function %s called\n", __func__);
	return 0;
}

//thread fun defincation
int thread_func(void *pv)
{
	int i = 0;
	while(!kthread_should_stop())
	{
		pr_info("In thread: %s, i=%d\n", __func__, i++);
		msleep(TIME_INTVL);
	}
	return 0;
}


static int __init my_thread_init(void)
{
	int ans;

	pr_info("Hello world from %s!\n", KBUILD_MODNAME);
	ans = alloc_chrdev_region(&dev, 0, 1, MY_DEV_NAME);
	if (ans<0)
	{
		pr_err("Error in major:minor allotment!\n");
		return -1;
	}
	pr_info("major:minor %d:%d allotted!\n", MAJOR(dev),MINOR(dev));

	// initialize a cdev
	cdev_init(&my_cdev, &fops);
	
	ans = cdev_add(&my_cdev, dev, 1);
	if (ans<0)
	{
		pr_err("Could not add cdev to the kernel!\n");
		goto r_cdev;
	}

	dev_class = class_create(THIS_MODULE, MY_CLASS_NAME);
	if (IS_ERR(dev_class))
	{
		pr_err("Could not create device class %s\n", MY_CLASS_NAME);
		goto r_class;
	}

	cdevice = device_create(dev_class, NULL, dev, NULL, MY_DEV_NAME);
	if (IS_ERR(cdevice))
	{
		pr_err("Could not create device %s\n", MY_DEV_NAME);
		goto r_device;
	}
	pr_info("Device %s under class %s created with success\n", 
			MY_DEV_NAME, MY_CLASS_NAME);
	
	
	return 0;

r_device:
        class_destroy(dev_class);
r_class:
        cdev_del(&my_cdev);
r_cdev:
        unregister_chrdev_region(dev, 1);

	return -1;
}

static void __exit my_thread_exit(void)
{
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);
	kthread_stop(thread);
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev, 1);
	
	return;
}

module_init(my_thread_init);
module_exit(my_thread_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD  Prasad Kulkarni <edd@cdac.gov.in>");
MODULE_DESCRIPTION("IOCTL-Thread on char device!");
