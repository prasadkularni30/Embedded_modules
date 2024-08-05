/*Write a kernel module that accepts data from user space via write calls, and keeps daaing into  kernel linked list
impliment a read() call which user space to read the status of the kernel linked list

Impliment an IOCTL to delete the kernel linked list*/

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

#include "my_ioctl.h" // user defined IOCTL file

//defining the class name and device name
#define CLASS_NAME	"prime_cls"
#define DEVICE_NAME	"prime_dev"

//node struct
struct prime_node
{
	int data;
	struct list_head my_list;
};

/*
unsigned int count = 0;
module_param(count, uint, S_IRUSR);


// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(count, "An integer variable to store lenght of linkedlist!");
*/

LIST_HEAD(prime_List); // Head of our Linked List


dev_t dev = 0; // var for major and minor number
static struct class *dev_class;
static struct device *cdevice;
static struct cdev my_cdev;

//----------------------------------------------FUNC PROTOTYPES------------------------------------------
static int __init my_mod_init(void);
static int my_open(struct inode *inode, struct file *file);
static ssize_t Write(struct file *file, const char __user *buf, size_t len, loff_t *off);
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static int my_release(struct inode *inode, struct file *file);
static void __exit my_mod_exit(void);


/*--------------------------------------------------FOPS STRUCTURE-----------------------------------------*/
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.write = Write,
	.unlocked_ioctl = my_ioctl,
	.release = my_release,
};


//---------------------------------------------FUNCTION DESCRIPTION--------------------------------------
static int my_open(struct inode *inode, struct file *file)
{
	pr_info("Opened Device\n");
	return 0;
}//my open ends

static ssize_t Write(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
	int temp=0,i=0;
	struct prime_node *node;

	
	if(copy_from_user((void *)&temp,(void *)buf, sizeof(int)))
	{
		pr_info("Could Not Write\n");
		return -1;
	}//copy from user ends
	for( i=2;i<=(temp/2);i++)
	{
		if((temp%i)==0)
		{
			//pr_info("not a prime\n");
			return len;
		}
	}
	
	node = (struct prime_node*)kmalloc(sizeof(struct prime_node), GFP_KERNEL);
	
	if(node == NULL) // null check
	{
		pr_alert("Space Full. Can't Create More Nodes");
		return -1;
	}
	node->data=temp;
	INIT_LIST_HEAD(&node->my_list);
	list_add(&node->my_list, &prime_List);
	pr_info("Added to List: %d\n", node->data);
	//count++;
	
	return len;
}//write ends

/*--------------------------------------------------IOCTL FUNC-----------------------------------*/
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct prime_node *tmp;

	switch(cmd)
	{
		case DISPLAY:
			list_for_each_entry_reverse(tmp, &prime_List, my_list)
			{
				pr_info("Prime_List: %d\n", tmp->data);
			}
			break;
		default:
			pr_alert("Invalid Command\n");
			break;
	}//switch ends
	return 0;
}

/*-----------------------------------------------RELEASE FUNC-----------------------------------*/
static int my_release(struct inode *inode, struct file *file)
{
	pr_info("My release function %s called\n", __func__);
	return 0;
}//release func ends


/*------------------------------------------------INIT FUNCTION------------------------------------*/
static int __init my_mod_init(void)
{
	int ans;

	pr_info("Hello world from %s!\n", KBUILD_MODNAME);
	ans = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
	if (ans<0)
	{
		pr_err("Error in major:minor allotment!\n");
		return -1;
	}
	pr_info("major:minor %d:%d allotted!\n", MAJOR(dev),MINOR(dev)); // to print major & minor

	// initialize a cdev
	cdev_init(&my_cdev, &fops);

	ans = cdev_add(&my_cdev, dev, 1);
	if (ans<0)
	{
		pr_err("Could not add cdev to the kernel!\n");
		goto r_cdev;
	}

	dev_class = class_create(THIS_MODULE, CLASS_NAME);
	if (IS_ERR(dev_class))
	{
		pr_err("Could not create device class %s\n", CLASS_NAME);
		goto r_class;
	}

	cdevice = device_create(dev_class, NULL, dev, NULL, DEVICE_NAME);
	if (IS_ERR(cdevice))
	{
		pr_err("Could not create device %s\n", DEVICE_NAME);
		goto r_device;
	}
	pr_info("Device %s under class %s created with success\n", 
			DEVICE_NAME, CLASS_NAME);
	return 0;

/*--------------------------------------ERROR LADDER--------------------------------------------*/
r_device:
        class_destroy(dev_class);
r_class:
        cdev_del(&my_cdev);
r_cdev:
        unregister_chrdev_region(dev, 1);

	return -1;
} // __init ends

/*-------------------------------------------------EXIT----------------------------------------*/
static void __exit my_mod_exit(void)
{
	struct prime_node *node, *tmp;
	
	list_for_each_entry_safe(node, tmp, &prime_List, my_list)
	{
		list_del(&node->my_list);
		kfree(node);
	}
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(dev, 1);
	pr_info("major:minor numbers freed up...\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD Ashish Bansal");
MODULE_DESCRIPTION("Linked list with user space");
MODULE_PARM_DESC(count, "To store the count for no of elements in Linked List");

