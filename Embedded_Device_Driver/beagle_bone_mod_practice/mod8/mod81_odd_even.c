/* Kernel thread basics */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/kthread.h>

static int odd_sleep=1;
static int even_sleep=2;

struct driver_info
{
	int sleep;
	char *name;
};

struct driver_info d[6];


module_param(odd_sleep, int, S_IRUGO );
module_param(even_sleep, int, S_IRUGO );

// define thread structs
static struct task_struct * thread[6];
static char * thread_name[6] = {"Thread-1","Thread-2","Thread-3","Thread-4","Thread-5","Thread-6"};


int thread_func(void *pv)
{
	int i = 0;
	struct driver_info *info=(struct driver_info *)pv;

	while(!kthread_should_stop())
	{
		
		pr_info("In %s i=%d\n\n", info->name, i++);
		msleep(info->sleep*1000);
	}
	return 0;
}


static int __init my_mod_init(void)
{
	int i=0,j=0;
	pr_info("Hello world from %s!\n", KBUILD_MODNAME);

	for(i=0;i<6;i++)
	{
		d[i].sleep = (i%2 ? even_sleep  : odd_sleep  );
		d[i].name=thread_name[i];
		
		thread[i] = kthread_run(thread_func, (void *)&d[i], thread_name[i]);
		if (thread[i])
			pr_info("Thread %s created!\n", thread_name[i]);
		else
		{
			pr_err("Cannot create thread %s\n", thread_name[i]);
			goto r_thread;
		}
	}
	
	return 0;
	
r_thread:
	for(j=0;j<i;j++)
	{
		kthread_stop(thread[j]);
	}
	return -1;
}

static void __exit my_mod_exit(void)
{
	int i=0;
	for(i=0;i<6;i++)
	{
		kthread_stop(thread[i]);
	}
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module to demo kernel threads!");
