/* Illustrate module parameters without callbacks */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

// instantiate the parameter variables with some defaults
// these will be overriden by insmod values, if any
static int myop = 100;
static int myint1 = 200;
static int myint2 = 300;
// register them with the kernel
// perms: all can read, only USR (root) can write/edit

// create MODULE DESC strings for modinfo
MODULE_PARM_DESC(myop, "Operation to perfomr");
MODULE_PARM_DESC(myint1, "First argument");
MODULE_PARM_DESC(myint2, "Second argument");

int notify_on_set(const char *val, const struct kernel_param *kp)
{

	int ret = param_set_int(val,kp) ;
	if (ret == 0)
	{
		pr_info("myop = %d\n", myop);
        pr_info("myint1 = %d\n", myint1);
        pr_info("myint2 = %d\n", myint2);
		if (myop == 1)
		{
			pr_info("Addition = %d\n",myint1+myint2);
		}

		else if (myop == 2)
		{
			pr_info("Substraction = %d\n",myint1-myint2);
		}

		else if (myop == 3)
		{
			pr_info("Multiplication = %d\n",myint1*myint2);
		}

		else if (myop == 4)
		{
			pr_info("Division = %d\n",myint1/myint2);
		}
		else {
			pr_err("invalid input\n");
		}
	
     }

	
	return 0;
}

const struct kernel_param_ops myops =
 {
    .set = &notify_on_set,  // my function - overrides default
	.get = &param_get_int,  // kernel's function - default
 };

module_param_cb(myop, &myops, &myop, S_IRUGO | S_IWUSR);
module_param(myint1, int, S_IRUGO | S_IWUSR);
module_param(myint2, int, S_IRUGO | S_IWUSR);

static int __init my_mod_init(void)
 {
         pr_info("Hello from mod24_prac!\n");
        pr_info("Update parameter myop1!\n[1]Add\n[2]Sub\n[3]Mul\n[4]Div\n");
         pr_info("myop = %d\n", myop);
        pr_info("myint1 = %d\n", myint1);
        pr_info("myint2 = %d\n", myint2);
         return 0;
 }


static void __exit my_mod_exit(void)
{
	pr_info("Goodbye from mod24_prac!\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module with param callback support!");

