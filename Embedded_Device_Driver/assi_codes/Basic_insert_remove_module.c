
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>

/*
Command used for:
Loading the module:	sudo insmod <modname.ko>
checking the prints:	dmesg (-w (optional))
Unloading the module:	sudo rmmod <modname.ko>
*/

static int __init my_mod_init(void)
{
	pr_info("Hey You!\n");
	return 0;
}

static void __exit my_mod_exit(void)
{
	pr_info("Logging Out!\n");
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prasad Kulkarni <prasak@gmail.com>");
MODULE_DESCRIPTION("Lab exam module!");
