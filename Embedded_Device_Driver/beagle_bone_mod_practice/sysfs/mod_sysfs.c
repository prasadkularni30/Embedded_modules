/* sysfs entry (directory and file) creation */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/jiffies.h>

#define PRN "240340130011"
#define PRN_SIZE 13

// ---- sysfs related ----
#define MY_SYSFS_DIR	"my_sysfs"
static char ID[PRN_SIZE];
static char foo[4];
// sysfs protos
static ssize_t ID_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t ID_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

static ssize_t jiffies_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t jiffies_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);
// sysfs kobject
struct kobject *kobj_ref;

// sysfs attr variable
struct kobj_attribute ID_attr = __ATTR(ID, 0660, ID_show, ID_store);
struct kobj_attribute jiffies_attr = __ATTR(jiffies, 0440, jiffies_show, jiffies_store);
struct kobj_attribute foo_attr = __ATTR(foo, 0660, foo_show, foo_store);

static struct attribute *attrs[] = {
	&ID_attr.attr,
	&jiffies_attr.attr,
	&foo_attr.attr,
	NULL,
};

static struct attribute_group attr_group = {
	.attrs =attrs,
};

// ---- sysfs related ----

// function prototypes
static int __init my_mod_init(void);
static void __exit my_mod_exit(void);

static ssize_t ID_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	pr_info("sysfs: read the sysfs variable %s\n", ID);
	strncpy(buf, ID, PRN_SIZE);
	return PRN_SIZE;
}

static ssize_t ID_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	size_t prn_len = strlen(PRN);
	pr_info("sysfs: write to sysfs variable: %s", buf);
	if(strlen(buf) < PRN_SIZE-1)
	{
		return -1;
	}
	else if(strncmp(buf, PRN, prn_len) == 0)
	{
		strncpy(ID, buf, PRN_SIZE);
		return count;
	}

	return -1;
}

static ssize_t jiffies_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	return count;
}


static ssize_t jiffies_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	pr_info("Jiffies Show\n");
	return sprintf(buf,"%lld",  get_jiffies_64());
}


static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	pr_info("foo store\n");
	if(strncmp(buf, "ON", 2)==0 || strncmp(buf, "OFF", 3)==0)
	{
		strncpy(foo, buf, strlen(buf));
		return count;
	}
	return 0;
}


static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	pr_info("foo Show\n");
	strncpy(buf,foo, strlen(foo));
	return strlen(foo);
}



static int __init my_mod_init(void)
{
	pr_info("Hello world from %s!\n", KBUILD_MODNAME);

	// create sysfs dir entry - under /sys/kernel/...
	kobj_ref = kobject_create_and_add(MY_SYSFS_DIR, kernel_kobj);
	if (kobj_ref==NULL)
	{
		pr_err("sysfs dir %s could not be created!\n", MY_SYSFS_DIR);
		goto r_sysfs_dir;
	}

	// create sysfs_int in my sysfs directory
	if (sysfs_create_group(kobj_ref, &attr_group))
	{
		pr_err("Cannot create sysfs group\n");
		goto r_sysfs_file;
	}

	pr_info("sysfs directory %s created under /sys/kernel\n", MY_SYSFS_DIR);

	return 0;

r_sysfs_file:
	kobject_put(kobj_ref);
r_sysfs_dir:
	return -1;
}

static void __exit my_mod_exit(void)
{
	sysfs_remove_group(kernel_kobj, &attr_group);
	pr_info("sysfs file removed\n");
	kobject_put(kobj_ref);
	pr_info("%s directory cleaned, kobject freed\n", MY_SYSFS_DIR);
	
	pr_info("Goodbye world from %s!\n", KBUILD_MODNAME);
	return;
}

module_init(my_mod_init);
module_exit(my_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ashish Bansal");
MODULE_DESCRIPTION("Directries and file entries in /sys (sysfs)");
