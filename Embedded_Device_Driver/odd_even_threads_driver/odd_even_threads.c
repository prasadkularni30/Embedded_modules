/*kernel odd threads even threads*/

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include<linux/module.h>
#include<linux/init.h>
#include<linux/delay.h>
#include<linux/kthread.h>
#include <linux/slab.h>


static int period_odd = 1000;
static int period_even = 1000;
static int num_threads = 2;

struct driver_info
{
	int sleep;
	char name[10];
};

struct driver_info *driv;

module_param(num_threads, int, S_IRUGO);
module_param(period_odd, int, S_IRUGO);
module_param(period_even, int, S_IRUGO);

MODULE_PARM_DESC(num_threads, "Integer variable for number of threads");
MODULE_PARM_DESC(period_odd, "Integer variable for delay (in milliseconds) of odd thread");
MODULE_PARM_DESC(period_odd, "Integer variable for delay (in milliseconds) of even thread");

static struct task_struct * *thread;


static int thread_fun(void *var)
{
	int i=0;
	struct driver_info *info=(struct driver_info *)var;
	
	pr_info("Entering in %s\n",info->name);
	while(!kthread_should_stop())
	{
		pr_info("In %s count: %d\n",info->name, i++);
		msleep(info->sleep);
	}

	pr_info("Exiting from %s\n",info->name);

	return 0;
}

static int __init my_init(void)
{
	int i=0;
	if(num_threads < 1 && num_threads > 20)  
	{
		pr_err("Number of threads should be a positive number\n");
		pr_err("Maximum number of threads board can handle are 20\n");
		return -1;
	}
	if(period_odd < 100 || period_even < 100)
	{
		pr_err("Enter period in miliseconds\n");
		pr_err("minimum time period should be 100ms\n");
		return -1;
	}
	
	driv=(struct driver_info *)kmalloc(sizeof(struct driver_info)*num_threads, GFP_KERNEL);
	if(driv==NULL)
	{
		pr_err("Memory allocation failed\n");
		return -1;
	}
	
	thread=(struct task_struct **)kmalloc(sizeof(struct task_struct *)*num_threads, GFP_KERNEL);
	if(thread==NULL)
	{
		pr_err("Memory allocation failed\n");
		goto k_free;
	}
	
	pr_info("Hello from %s!\n",KBUILD_MODNAME);
	
	for(i=0;i<num_threads;i++)
	{
		driv[i].sleep = (i%2 ? period_even : period_odd);
		sprintf(driv[i].name,"Thread-%d",i+1);
		
		thread[i] = kthread_run(thread_fun , (void *)&driv[i],driv[i].name);
		if(thread[i])
			pr_info("%s created!\n",driv[i].name);
		else
		{
			pr_err("Cannot create %s!\n",driv[i].name);
			goto r_thread;
		}
	}



	return 0;

r_thread:
	for(i-=1;i>=0;i--)
	{
		kthread_stop(thread[i]);
	}
	kfree(thread);
k_free:
	kfree(driv);
return -1;

}

static void __exit my_exit(void)
{
	int i=0;
	for(i=0;i<num_threads;i++)
	{
		kthread_stop(thread[i]);
	}
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);

	return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD  Prasad Kulkarni <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module to create ODD Even kernel threads!");
