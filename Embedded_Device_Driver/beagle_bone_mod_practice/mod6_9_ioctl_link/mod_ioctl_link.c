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
#include <linux/slab.h>
#include <linux/list.h>

#include "my_ioctls.h"

#define MY_CLASS_NAME	"linked_list_cls"
#define MY_DEV_NAME	"linked_list_dev"

unsigned int list_length=0;

module_param(list_length, uint, S_IRUGO);

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(list_length, "An integer variable to store lenght of linkedlist!");

// internal kernel variable - used for ioctl
//static unsigned int value;

dev_t dev = 0;

static struct class *dev_class;
static struct device *cdevice;
static struct cdev my_cdev;

// linked list node definition
struct my_node
{
	int data;
	struct list_head my_list;
};

// create list head pointer/node
LIST_HEAD(my_head);

// function prototypes
static int __init my_mod_init(void);
static int my_open(struct inode *inode, struct file *file);
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long args);
static int my_release(struct inode *inode, struct file *file);
static void __exit my_mod_exit(void);

static int my_open(struct inode *inode, struct file *file)
{
	pr_info("My open function %s called\n", __func__);
	return 0;
}

static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	int count;
	int *karr;
	struct my_node *node, *tmp;
	struct my_node *t;
	switch(cmd)
	{
		case WRITE_TO_LIST:
			node = (struct my_node *)kmalloc(sizeof(struct my_node), GFP_KERNEL);
			
			if ( copy_from_user((void *)&node->data, (unsigned int *)arg, sizeof(node->data)) )
			{
				pr_err("Error writing from kernel variable\n");
			}
			INIT_LIST_HEAD(&node->my_list);
			list_add(&node->my_list, &my_head);
			
			list_length++;
			
			pr_info("Kernel variable read, value = %d\n", node->data);
			pr_info("Write Success!!\n");
			
			break;
		case READ_FROM_LIST:
			count  = 0;
			
			karr=(int *)kmalloc(sizeof(int)*list_length,GFP_KERNEL);
			
			list_for_each_entry_reverse(tmp, &my_head, my_list)
			{
				karr[count]=tmp->data;
				pr_info("Node %d, data=%d\n", ++count, tmp->data);
			}
			if( copy_to_user((unsigned int *)arg,(void *)karr, sizeof(int)*list_length ) )
			{
				pr_err("Error writing to kernel variable\n");
			}
			pr_info("Read Done!!\n");
			kfree(karr);
			break;
		case DELETE_LIST:
		
			list_for_each_entry_safe(tmp, t, &my_head, my_list)
			{	// delete the node and free its instantiations
				pr_info("Deleting node with data=%d\n", tmp->data);
				list_del(&tmp->my_list);
				kfree(tmp);
			}
			list_length=0;
			pr_info("Deleted Linked List\n");
			
			break;
		default:
		
			pr_err("Undefined command!\n");
			break;
	}
	return 0;
}

static int my_release(struct inode *inode, struct file *file)
{
	pr_info("My release function %s called\n", __func__);
	return 0;
}

// create a fops struct
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.unlocked_ioctl = my_ioctl,
	.release = my_release,
};

static int __init my_mod_init(void)
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

static void __exit my_mod_exit(void)
{
	struct my_node *node, *tmp;
	
	list_for_each_entry_safe(node, tmp, &my_head, my_list)
	{	// delete the node and free its instantiations
		pr_info("Deleting node with data=%d\n", node->data);
		list_del(&node->my_list);
		kfree(node);
	}
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev, 1);
	pr_info("major:minor numbers freed up...\n");
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("IOCTL on char device!");
