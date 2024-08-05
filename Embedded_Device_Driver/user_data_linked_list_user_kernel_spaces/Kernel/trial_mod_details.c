
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

#include "details.h" // header file containing commands

//defining the class name and device name
#define CLASS_NAME	"details_cls"
#define DEVICE_NAME	"details_dev"

//node struct
struct details_list
{
	struct details dets;
	struct list_head my_dets_list;
};


LIST_HEAD(ab_List); // Head of AB Linked List
LIST_HEAD(cd_List); // Head of CD Linked List
LIST_HEAD(ef_List); // Head of Ef Linked List
LIST_HEAD(gh_List); // Head of GH Linked List
LIST_HEAD(err_List); // Head of Err Linked List


dev_t dev = 0; // var for major and minor number
static struct class *dev_class;
static struct device *cdevice;
static struct cdev my_cdev;

//variables to count length of linnked list

static int ab_count=0;
static int cd_count=0;
static int ef_count=0;
static int gh_count=0;
static int err_count=0;

module_param(ab_count, int, S_IRUGO);
module_param(cd_count, int, S_IRUGO);
module_param(ef_count, int, S_IRUGO);
module_param(gh_count, int, S_IRUGO);
module_param(err_count,int,S_IRUGO);


MODULE_PARM_DESC(ab_count,"Variable to store count of AB-LINK_LIST");
MODULE_PARM_DESC(cd_count,"Variable to store count of CD-LINK_LIST");
MODULE_PARM_DESC(ef_count,"Variable to store count of EF-LINK_LIST");
MODULE_PARM_DESC(gh_count,"Variable to store count of GH-LINK_LIST");
MODULE_PARM_DESC(err_count,"Variable to store count of ERR-LINK_LIST");

//FUNC PROTOTYPES
static int __init my_mod_init(void);
static int my_open(struct inode *inode, struct file *file);
static ssize_t Write(struct file *file, const char __user *buf, size_t len, loff_t *off);
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static int my_release(struct inode *inode, struct file *file);
static void __exit my_mod_exit(void);
static void cleanup(void);
static int add_to_list(struct details );
static int transfer(struct list_head *, unsigned long );
static void display_dmesg(struct list_head *);


//FOPS STRUCTURE
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = my_open,
	.write = Write,
	.unlocked_ioctl = my_ioctl,
	.release = my_release,
};


//FUNCTION DESCRIPTION
static int my_open(struct inode *inode, struct file *file)
{
	pr_info("Opened Device\n");
	return 0;
}//my open ends

static ssize_t Write(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
	struct details temp;
	
	

	if(copy_from_user((void *)&temp,(void *)buf, sizeof(struct details)))
	{
		pr_info("Could Not Write\n");
		return -1;
	}//copy from user ends

	len=add_to_list(temp);
	
	return len;
}//write ends

/*--------------------------------------------------IOCTL FUNC-----------------------------------*/
static long my_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{

	

	switch(cmd)
	{
		case DISP_AB:
			pr_info("Printing linked-list National_ID: AB\n");
			display_dmesg(&ab_List);
			break;
		case DISP_CD:
			pr_info("Printing linked-list National_ID: CD\n");
			display_dmesg(&cd_List);
			break;
		case DISP_EF:
			pr_info("Printing linked-list National_ID: EF\n");
			display_dmesg(&ef_List);
			break;
		case DISP_GH:
			pr_info("Printing linked-list National_ID: GH\n");
			display_dmesg(&gh_List);
			break;
		case DISP_ERR:
			pr_info("Displaying Error linked-list \n");
			display_dmesg(&err_List);
			break;
		case READ_AB:
			transfer(&ab_List,arg);
			break;
		case READ_CD:
			transfer(&cd_List,arg);
			break;
		case READ_EF:
			transfer(&ef_List,arg);
			break;
		case READ_GH:
			transfer(&gh_List,arg);
			break;
		case READ_ERR:
			transfer(&err_List,arg);
			break;
		case CLEANUP:
			cleanup();
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


//function to Add to Linked-List

int add_to_list(struct details info)
{
	int i=0;
	struct details_list *node;

	node = (struct details_list *)kmalloc(sizeof(struct details_list), GFP_KERNEL);
	if(node == NULL) // null check
	{
		pr_alert("Space Full. Can't Create More Nodes");
		return -1;
	}
	//node->dets=temp;	//error will only pass the address of variable received bad practice
				// use memcpy or strncpy

	memcpy((void *)&node->dets,(void *)&info, sizeof(struct details));	

	//strncpy(node->dets.name,temp.name,strlen(temp.name));
	//strncpy(node->dets.address,temp.address,strlen(temp.address));
	//strncpy(node->dets.id,temp.id,strlen(temp.id));
	
	INIT_LIST_HEAD(&node->my_dets_list);

	if(strlen(node->dets.id)!=6)
	{
		pr_err("National ID did not matched data added to error linked-list\n");
		list_add(&node->my_dets_list, &err_List);
		err_count++;
		return 1;
	}
	
	for(i=2;i<6;i++)
	{
		if( (node->dets.id[i] <= 48) || (node->dets.id[i] >= 57) )
		{
			pr_err("National ID did not matched data added to error linked-list\n");
			list_add(&node->my_dets_list, &err_List);
			err_count++;
			return 1;
		}
	}
	
	if( !(strncmp(node->dets.id,"AB",2)) )
	{
		list_add(&node->my_dets_list, &ab_List);
		ab_count++;
	}
	else if( !(strncmp(node->dets.id,"CD",2)) )
	{
		list_add(&node->my_dets_list, &cd_List);
		cd_count++;
	}
	else if( !(strncmp(node->dets.id,"EF",2)) )
	{
		list_add(&node->my_dets_list, &ef_List);
		ef_count++;
	}
	else if( !(strncmp(node->dets.id,"GH",2)) )
	{
		list_add(&node->my_dets_list, &gh_List);
		gh_count++;
	}
	else
	{
		pr_err("National ID did not matched data added to error linked-list\n");
		list_add(&node->my_dets_list, &err_List);
		err_count++;
	}
	
	return 1;
	
}


//fucntion to display in dmesg

void display_dmesg(struct list_head *head)
{
	struct details_list *tmp;

	pr_info("Printing linked-list National_ID: AB\n");
	
	list_for_each_entry(tmp, head, my_dets_list)
	{
		pr_info("\n");
		pr_info("%s, %s, %s \n", tmp->dets.name,tmp->dets.address,tmp->dets.id);
		pr_info("-----------------------------------\n");
	}

	pr_info("-----------");
}

//fucntion to copy to user
int transfer(struct list_head *head, unsigned long arg)
{
	struct details_list *tmp;
	int offset=0;

	pr_info("transfering data to user\n");
	offset = 0;
	list_for_each_entry(tmp, head, my_dets_list)
	{
		if( copy_to_user((void *)((struct details *)arg+offset), (void*)&tmp->dets, sizeof(struct details)) ) 
		{	// to read from linked list and write in user_buffer + offset location
			
			pr_alert("Failed to copy to user space\n");
			return -1;
		}
		offset++; // move to next index according to the integers size
		
	}

	return 0;

}

void cleanup(void )
{
	struct details_list *node,*tmp;

	pr_info("Deleting All linked-lists Data\n");

	list_for_each_entry_safe(node, tmp, &ab_List, my_dets_list)
	{
		list_del(&node->my_dets_list);
		kfree(node);
	}
	list_for_each_entry_safe(node, tmp, &cd_List, my_dets_list)
	{
		list_del(&node->my_dets_list);
		kfree(node);
	}
	list_for_each_entry_safe(node, tmp, &ef_List, my_dets_list)
	{
		list_del(&node->my_dets_list);
		kfree(node);
	}
	list_for_each_entry_safe(node, tmp, &gh_List, my_dets_list)
	{
		list_del(&node->my_dets_list);
		kfree(node);
	}
	list_for_each_entry_safe(node, tmp, &err_List, my_dets_list)
	{
		list_del(&node->my_dets_list);
		kfree(node);
	}
	ab_count=0;
	cd_count=0;
	ef_count=0;
	gh_count=0;
	err_count=0;					
}



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
	pr_info("Device %s under class %s created with success\n",DEVICE_NAME, CLASS_NAME);
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
	struct details_list * node,* tmp;
	
	pr_info("Deleting All linked-lists Data\n");
			list_for_each_entry_safe(node, tmp, &ab_List, my_dets_list)
			{
				list_del(&node->my_dets_list);
				kfree(node);
			}
			list_for_each_entry_safe(node, tmp, &cd_List, my_dets_list)
			{
				list_del(&node->my_dets_list);
				kfree(node);
			}
			list_for_each_entry_safe(node, tmp, &ef_List, my_dets_list)
			{
				list_del(&node->my_dets_list);
				kfree(node);
			}
			list_for_each_entry_safe(node, tmp, &gh_List, my_dets_list)
			{
				list_del(&node->my_dets_list);
				kfree(node);
			}
			list_for_each_entry_safe(node, tmp, &err_List, my_dets_list)
			{
				list_del(&node->my_dets_list);
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
MODULE_AUTHOR("EDD  Prasad Kulkarni <edd@cdac.gov.in");
MODULE_DESCRIPTION("Linked list with user space");


