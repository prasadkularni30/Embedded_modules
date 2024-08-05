#define pr_fmt(fmt) KUILD_MODNAME": " fmt 

#include<linux/module.h>
#include<linux/init.h>


static char string [] = "CDAC";
static int num = -110;

static int  __init Init(void)
{
	pr_info("hello %s\n",string);
	return 0;
}

static void __exit Exit(void)
{
	pr_alert("bye %d\n",num);
	return ;
}

module_init(Init);
module_exit(Exit);



