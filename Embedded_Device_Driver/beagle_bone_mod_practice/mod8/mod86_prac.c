/* Kernel threads with read-write locks */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/string.h>
#include <linux/rwlock.h>

#define WTIME_INTVL	(1000)	// milliseconds
#define RTIME_INTVL	(1000)	// milliseconds
#define BUF_SZ		(1024)	// in bytes

// define thread structs
static struct task_struct *wthread;
static struct task_struct * rthread[10];
static char wthread_name[] = "WThread";
static char *rthread1_name[10] = {"RThread-1","RThread-2","RThread-3","RThread-4","RThread-5","RThread-6","RThread-7","RThread-8","RThread-9","RThread-10"};
 

// shared data - wthread writes, rthreads only read
static int count = 0;

// rwlock
static DEFINE_RWLOCK(my_rwlock);

int wthread_func(void *pv)
{
	char buffer[20] = {0};

	while(!kthread_should_stop())
	{
		write_lock(&my_rwlock);
		sprintf(buffer, "%s:%d->%d", wthread_name, count++, count);
		pr_info("In thread %s, got wlock, buffer=%s\n", __func__, buffer);
		write_unlock(&my_rwlock);
		msleep(WTIME_INTVL);
	}
	do_exit(0);
	return 0;
}

int rthread_func(void *pv)
{
	char buffer[20] = {0};
	char *thread_name = (char *)pv;

	while(!kthread_should_stop())
	{
		read_lock(&my_rwlock);
		sprintf(buffer, "%s:%d", thread_name, count);
		pr_info("In thread %s, got rlock, buffer=%s\n", __func__, buffer);
		read_unlock(&my_rwlock);
		msleep(RTIME_INTVL);
	}
	do_exit(0);
	return 0;
}

static int __init my_mod_init(void)
{
	int i=0;
	
	pr_info("Hello world from %s!\n", KBUILD_MODNAME);
	

	for(i=0;i<5;i++)
	{
		//sprintf(rthread1_name[i],"rthread1_name-%d",i+1);
		rthread[i] = kthread_run(rthread_func, rthread1_name[i], rthread1_name[i]);
		if (rthread[i])
			pr_info("Thread %s created!\n", rthread1_name[i]);
		else
		{
			pr_err("Cannot create thread %s\n", rthread1_name[i]);
			goto r_thread;
		}
		
	}
	wthread = kthread_run(wthread_func, NULL, wthread_name);
	if (wthread)
		pr_info("Thread %s created!\n", wthread_name);
	else
	{
		pr_err("Cannot create thread %s\n", wthread_name);
		goto r_thread1;
	}

	

	return 0;

r_thread1:
	
	kthread_stop(wthread);
r_thread:
	for(i-=1;i>=0;i--) kthread_stop(rthread[i]);
	return -1;
}

static void __exit my_mod_exit(void)
{
	int i=0;
	kthread_stop(wthread);
	for(i=0;i<5;i++) kthread_stop(rthread[i]);
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);

	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Module to demo rwlock!");
