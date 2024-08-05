
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>


static int myops = 100;
static int myint1 = 200;
static int myint2 = 300;


module_param(myops, int, S_IRUGO | S_IWUSR);
module_param(myint1, int, S_IRUGO | S_IWUSR);
module_param(myint2, int, S_IRUGO | S_IWUSR);

MODULE_PARM_DESC(myops, "Integer variable assigned for operantion");
MODULE_PARM_DESC(myint1, "Integer Variable Operand 1");
MODULE_PARM_DESC(myint2, "Integer Variable Operand 2");

static int __init my_mod_init(void)
{
	pr_info("Hello from mod21!\n");

	if(myops==1)
	{
		pr_info("Additon: %d\n",myint1+myint2);
	}
	else if(myops==2)
	{
		pr_info("Subtraction: %d\n",myint1-myint2);
	}
	else if(myops==3)
	{
		pr_info("Multiplication: %d\n",myint1*myint2);
	}
	else if(myops==4)
	{
		pr_info("Division: %d\n",myint1/myint2);
	}
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Goodbye from mod21!\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module with param support!");
