//Linked list program
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/list.h>


//node structure
struct entry_list_node
{
	int data;
	struct list_head my_entry_list;
};


LIST_HEAD(entry_List); // Head of Entry Linked List

//variable to count length of linnked list
static int count = 0;

//valiable to take input from kernel
static int size = 0;
static int myop = 0;
static int entry = 0 ;

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(size,"Integer Variable for size of an Linked_List");
MODULE_PARM_DESC(count,"Integer Variable for count of linked_list");
MODULE_PARM_DESC(myop,"Integer Variable for options");
MODULE_PARM_DESC(entry,"Integer Variable to store the position to delete");


//FUNC PROTOTYPES
static int __init my_init(void);
static void __exit my_exit(void);
static void cleanup(void);
static int entry_del(void);
static void display(void);


//function for paramater option menu
int notify_on_set(const char *val, const struct kernel_param *kp)
{

	int ret = param_set_int(val,kp) ;
	if (ret == 0)
	{
		pr_info("Option = %d\n", myop);
		switch(myop)
		{
			case 1:
				pr_info("Deleting entry\n");
				entry_del();
				break;
			case 2:
				display();
				break;
			case 3:
				cleanup();
				break;
			case 4:
				if(size==count)
				pr_info("Linked_list is full\n");
				pr_info("Size: %d, Entries: %d\n",size,count);
				break;
			default:
				pr_err("invalid input\n");
				break;
		}
		pr_info("Update parameter myop!\n[1]Delete entry\n[2]Display data\n[3]Delete full list\n");
		pr_info("Note: if Deleting Entry\n Enter position in parameter Entry\n");
     }
	return 0;
}

const struct kernel_param_ops myops =
{
  	.set = &notify_on_set,  // my function - overrides default
	.get = &param_get_int,  // kernel's function - default
};

//command line and module parameters declaration
module_param_cb(myop, &myops, &myop, S_IRUGO | S_IWUSR);
module_param(size, int, S_IRUGO );
module_param(count, int, S_IRUGO );
module_param(entry, int, S_IRUGO | S_IWUSR);



//fucntion to display in dmesg
void display(void)
{
	struct entry_list_node *tmp;
	int i=0;
	list_for_each_entry(tmp, &entry_List, my_entry_list)
	{
		pr_info("\n");
		pr_info("Entry[%d]: %d\n",i, tmp->data);
		pr_info("-----------------------------------\n");
		i++;
	}
	
	pr_info("-----------\n");
}

//fucntion to delete particular entry
int entry_del(void)
{
	struct entry_list_node *tmp, *node;
	int i=0;

	if(entry==0){ pr_err("enter which entry to delete before choosing option\n"); return 0; }
	if(entry>count){ pr_err("No node at position\n Total entries in List: %d\n",count); return 0; } 
	
	pr_info("Deleting Entry\n");
	list_for_each_entry_safe(node, tmp, &entry_List, my_entry_list)
	{
		if(i==entry)
		{
			list_del(&node->my_entry_list);
			kfree(node);
			count--;
			break;
		}
		i++;
	}

	return 0;

}

//function to delete all data
void cleanup(void )
{
	struct entry_list_node *node,*tmp;

	pr_info("Deleting All linked-lists Data\n");

	list_for_each_entry_safe(node, tmp, &entry_List, my_entry_list)
	{
		list_del(&node->my_entry_list);
		kfree(node);
	}
	count=0;					
}


/*------------------------------------------------INIT FUNCTION------------------------------------*/
static int __init my_init(void)
{
	int i;
	struct entry_list_node *node, *tmp;
	if(size<=0)
	{
		pr_err("Enter size of list\n");
		if(size < 0){ pr_err("size cannot be a in Negative\n"); }
		return -1;
	}
	pr_info("Hello from %s\n",KBUILD_MODNAME);
	pr_info("Creating linked_list\n");
	for(i=0;i<size/2;i++)
	{
		pr_info("Entry [%d]",i+1);
		node=(struct entry_list_node *)kmalloc(sizeof(struct entry_list_node),GFP_KERNEL);
		if(node == NULL) // null check
		{
			pr_alert("Memory allocation failed\n");
			goto k_free;
		}
		node->data=(i+1)*10;
		INIT_LIST_HEAD(&node->my_entry_list);
		
		list_add(&node->my_entry_list, &entry_List);
		count++;
	}
	
	for(i=i;i<size;i++)
	{
		pr_info("Reserse Entry [%d]",i);
		node=(struct entry_list_node *)kmalloc(sizeof(struct entry_list_node),GFP_KERNEL);
		if(node == NULL) // null check
		{
			pr_alert("Memory allocation failed\n");
			goto k_free;
		}
		node->data=(i+1)*10;
		INIT_LIST_HEAD(&node->my_entry_list);
		
		list_add_tail(&node->my_entry_list, &entry_List);
		count++;
	}
	
	pr_info("List added successfully\n");
	pr_info("Update parameter myop!\n[1]Delete entry\n[2]Display data\n[3]Delete full list\n");
	pr_info("Note: if Deleting Entry\n Enter position in parameter Entry\n");
	
	return 0;

/*--------------------------------------ERROR LADDER--------------------------------------------*/
k_free:
	pr_err("Error occured while entering data\n");
	pr_err("Clearing linked_list\n");
	list_for_each_entry_safe(node, tmp, &entry_List, my_entry_list)
	{
		list_del(&node->my_entry_list);
		kfree(node);
	}
	count=0;
	
	return -1;
} // __init ends

/*-------------------------------------------------EXIT FUNCTION----------------------------------------*/
static void __exit my_exit(void)
{
	struct entry_list_node *node, *tmp;
	
	list_for_each_entry_safe(node, tmp, &entry_List, my_entry_list)
	{
		list_del(&node->my_entry_list);
		kfree(node);
	}
	pr_info("All Data cleared\n");
	pr_info("Goodbye from %s!\n", KBUILD_MODNAME);
	
	return;
}// __exit ends

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prasad Kulkarni <Prasadk@gmail.com>");
MODULE_DESCRIPTION("Linked list");
