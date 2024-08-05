
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

static int myops = 10;
static int mym = 20;
#define SIZE	(10)
static long myarr[SIZE] = {0};
static int count = 0;

module_param_array(myarr, long, &count, S_IRUGO | S_IWUSR);
module_param(myops,int,S_IRUGO | S_IWUSR);
module_param(mym,int,S_IRUGO | S_IWUSR);


MODULE_PARM_DESC(myops, "Integer variable set for Operation");
MODULE_PARM_DESC(mym, "Integer Variable to store Minimum or Maximum value");
MODULE_PARM_DESC(myarr, "This is an array variable of longs");

static int __init my_mod_init(void)
{
	int i;
	pr_info("Hello from mod25!\n");
	pr_info("For myarr, we got %d entries\n", count);
	for (i=0;i<count;i++)
	{
		pr_info("myarr[%d]=%ld\n", i, myarr[i]);
	}
	if(myops==1)
	{
		mym=myarr[0];
		for(i=0;i<count;i++)
		{
			if(mym>myarr[i])
				mym=myarr[i];
		}
		pr_info("Minimum Element in Array is : %d\n",mym);
	}
	else if(myops==2)
	{
		mym=myarr[0];
		for(i=0;i<count;i++)
		{
			if(mym<myarr[i])
				mym=myarr[i];
		}
		pr_info("Maximum Element in Array is : %d\n",mym);
	}
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Goodbye from mod25!\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module with param support!");
