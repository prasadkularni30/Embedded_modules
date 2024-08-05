/* sysfs entry (directory and file) creation */
//check directory  /sys/kernel/my_sysfs/sysfs_init

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/string.h>


// ---- sysfs related ----
#define MY_SYSFS_DIR	"my_sysfs" //directory name
static volatile int sysfs_int = 0;
// sysfs protos
static ssize_t my_sysfs_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);//cat 
static ssize_t my_sysfs_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count); //echo
// sysfs kobject
struct kobject *kobj_ref;// struct ptr 
// sysfs attr variable
struct kobj_attribute my_sysfs_attr = __ATTR(sysfs_int, 0660, my_sysfs_show, my_sysfs_store); //defining file attributes for file "sysfs_init"
// ---- sysfs related ----

// function prototypes
static int __init my_mod_init(void);
static void __exit my_mod_exit(void);

static ssize_t my_sysfs_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	pr_info("sysfs: read the sysfs variable\n");
	return sprintf(buf, "%d", sysfs_int);
}

static ssize_t my_sysfs_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	pr_info("sysfs: write to sysfs variable: %s", buf);
	sscanf(buf, "%d", &sysfs_int);
	return count;
}

static int __init my_mod_init(void)
{
	pr_info("Hello world from %s!\n", KBUILD_MODNAME);

	// create sysfs dir entry - under /sys/kernel/...
	kobj_ref = kobject_create_and_add(MY_SYSFS_DIR, kernel_kobj); //creating a directory in psudo file sys (ret ptr to struct kobject(directory we created))
	if (kobj_ref==NULL)
	{
		pr_err("sysfs dir %s could not be created!\n", MY_SYSFS_DIR);
		goto r_sysfs_dir;
	}

	// create sysfs_int in my sysfs directory
	if (sysfs_create_file(kobj_ref, &my_sysfs_attr.attr)) // creating a file named as "sysfs_init" in the psudo file system directory (use .attr)
	{
		pr_err("Cannot create sysfs file\n");
		goto r_sysfs_file;
	}

	pr_info("sysfs directory %s created under /sys/kernel\n", MY_SYSFS_DIR);

	return 0;

//+++++++++++++++++++++++++++++++++++++++++++++++++error ladder+++++++++++++++++++++++++++++++++++++++++++
r_sysfs_file:
	kobject_put(kobj_ref);
r_sysfs_dir:
	return -1;
}


//
static void __exit my_mod_exit(void)
{
	sysfs_remove_file(kernel_kobj, &my_sysfs_attr.attr); //to remove the directory
	pr_info("sysfs file removed\n");
	kobject_put(kobj_ref);
	pr_info("%s directory cleaned, kobject freed\n", MY_SYSFS_DIR);
	
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Directries and file entries in /sys (sysfs)");
