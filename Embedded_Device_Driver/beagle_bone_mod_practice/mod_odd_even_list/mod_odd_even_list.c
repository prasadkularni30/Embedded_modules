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
#define CLASS_NAME	"even_odd_cls"
#define DEVICE_NAME	"even_odd_dev"

//node struct
struct even_node
{
	int even_data;
	struct list_head my_even_list;
};

struct odd_node
{
	int odd_data;
	struct list_head my_odd_list;
};

unsigned int even_count = 0;
module_param(even_count, uint, S_IRUSR);

unsigned int odd_count = 0;
module_param(odd_count, uint, S_IRUSR);

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(even_count, "An integer variable to store lenght of even linkedlist!");
MODULE_PARM_DESC(odd_count, "An integer variable to store lenght of odd linkedlist!");

LIST_HEAD(even_List); // Head of our Linked List
LIST_HEAD(odd_List); // Head of our Linked List

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
	int temp=0;
	struct even_node *e_node;
	struct odd_node *o_node;
	
	if(copy_from_user((void *)&temp,(void *)buf, sizeof(int)))
	{
		pr_info("Could Not Write\n");
		return -1;
	}//copy from user ends
	if( !(temp%2))
	{
		e_node = (struct even_node*)kmalloc(sizeof(struct even_node), GFP_KERNEL);
		
		if(e_node == NULL) // null check
		{
			pr_alert("Space Full. Can't Create More Nodes");
			return -1;
		}
		e_node->even_data=temp;
		INIT_LIST_HEAD(&e_node->my_even_list);
		list_add(&e_node->my_even_list, &even_List);
		even_count++;
	}
	else
	{	
		o_node = (struct odd_node*)kmalloc(sizeof(struct odd_node), GFP_KERNEL);
		if(o_node == NULL) // null check
		{
			pr_alert("Space Full. Can't Create More Nodes");
			return -1;
		}
		o_node->odd_data=temp;
		INIT_LIST_HEAD(&o_node->my_odd_list);
		list_add(&o_node->my_odd_list, &odd_List);
		odd_count++;
	}
	return len;
}//write ends

/*--------------------------------------------------IOCTL FUNC-----------------------------------*/
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct even_node *e_node, *e_tmp;
	struct odd_node *o_node, *o_tmp;
	
	int offset = 0;
	switch(cmd)
	{
		case GET_EVEN:
			offset = 0;
			list_for_each_entry_reverse(e_tmp, &even_List, my_even_list)
			{
				if( copy_to_user((void *)((int *)arg+offset), (void*)&e_tmp->even_data, sizeof(int)) ) 
				{	// to read from linked list and write in user_buffer + offset location
					
					pr_alert("Failed to copy to user space\n");
					return -1;
				}
				offset++; // move to next index according to the integers size

				pr_info("Data = %d\n", e_tmp->even_data); // To display what data was read from kernel space
			}//lsit for each entry ends
			break;
		case GET_ODD:
			offset = 0;
			list_for_each_entry_reverse(o_tmp, &odd_List, my_odd_list)
			{
				if( copy_to_user((void *)((int *)arg+offset), (void *)&o_tmp->odd_data, sizeof(int)) ) 
				{	// to read from linked list and write in user_buffer + offset location
					
					pr_alert("Failed to copy to user space\n");
					return -1;
				}
				offset++; // move to next index according to the integers size

				pr_info("Data = %d\n", o_tmp->odd_data); // To display what data was read from kernel space
			}//lsit for each entry ends
			break;
		case DISPLAY_EVEN:
			list_for_each_entry_reverse(e_tmp, &even_List, my_even_list)
			{
				pr_info("Even List: %d\n", e_tmp->even_data);
			}
			break;
		case DISPLAY_ODD:
			list_for_each_entry_reverse(o_tmp, &odd_List, my_odd_list)
			{
				pr_info("Odd List: %d\n", o_tmp->odd_data);
			}
			break;
		case DELETE_EVEN:
			pr_info("Deleting All Data\n");
			list_for_each_entry_safe(e_node, e_tmp, &even_List, my_even_list)
			{
				pr_info("Deleting %d\n", e_node->even_data);
				list_del(&e_node->my_even_list);
				kfree(e_node);
			}//list for each entry ends						
			even_count = 0;
			break;
		case DELETE_ODD:
			pr_info("Deleting All Data\n");
			list_for_each_entry_safe(o_node, o_tmp, &odd_List, my_odd_list)
			{
				pr_info("Deleting %d\n", o_node->odd_data);
				list_del(&o_node->my_odd_list);
				kfree(o_node);
			}//list for each entry ends						
			odd_count = 0;
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
	struct even_node *e_node, *e_tmp;
	struct odd_node *o_node, *o_tmp;
	list_for_each_entry_safe(e_node, e_tmp, &even_List, my_even_list)
	{
		list_del(&e_node->my_even_list);
		kfree(e_node);
	}
	list_for_each_entry_safe(o_node, o_tmp, &odd_List, my_odd_list)
	{
		list_del(&o_node->my_odd_list);
		kfree(o_node);
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

