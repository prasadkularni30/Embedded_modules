/* Illustrate module parameters with callbacks */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

// instantiation with default, overriden by insmod if any
static int myop = 100;
#define SIZE	(10)
static long myarr[SIZE] = {0};
static int count = 0;

int notify_on_set(const char *val, const struct kernel_param *kp)
{
	int i=0,mym;
	int ans = param_set_int(val, kp);
	
	if (ans==0)
	{
		pr_info("Callback function %s called\n", __func__);
		pr_info("New value of myop = %d\n", myop);
	
		if(myop==1)
		{
			mym=myarr[0];
			for(i=0;i<count;i++)
			{
				if(mym>myarr[i])
					mym=myarr[i];
			}
			pr_info("Minimum Element in Array is : %d\n",mym);
		}
		else if(myop==2)
		{
			mym=myarr[0];
			for(i=0;i<count;i++)
			{
				if(mym<myarr[i])
					mym=myarr[i];
			}
		pr_info("Maximum Element in Array is : %d\n",mym);
		}
		else
		{
			pr_alert("Invalid Choice\n[1]Min value\n[2]Max Value\n");
		}	
	}
	return 0;
}

const struct kernel_param_ops myops = 
{
	.set = &notify_on_set,		// my function - overrides default
	.get = &param_get_int, 	// kernel's function - default
};

// perms: all can read, only USR (root) can write/edit
module_param_cb(myop, &myops, &myop, S_IRUGO | S_IWUSR);
module_param_array(myarr,long,&count,S_IRUGO | S_IWUSR);

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(myops, "Integer variable set for Operation");
MODULE_PARM_DESC(myarr, "This is an array variable of longs");

static int __init my_mod_init(void)
{
	int i;
	pr_info("Hello from mod22!\n");
	pr_info("For array, we got %d entries\n", count);
	for (i=0;i<count;i++)
	{
		pr_info("myarr[%d]=%ld\n", i, myarr[i]);
	}
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Bye from mod26!\n");

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module with param callback support!");
