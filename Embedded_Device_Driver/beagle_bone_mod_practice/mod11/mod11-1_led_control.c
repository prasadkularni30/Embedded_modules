#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>       
#include <linux/kobject.h>    
#include <linux/kthread.h>    
#include <linux/delay.h>


static struct kobject *kobj_ref;

static unsigned int gpioLED = 48;

static char ledName[10] = {0};
static bool ledOn = 0;                      
enum modes { OFF, ON };          // LED modes    
static enum modes mode = ON;		// default LED mode


static ssize_t mode_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf){
   switch(mode){
      case OFF:   return sprintf(buf, "off\n");
      case ON:    return sprintf(buf, "on\n");
      default:    return sprintf(buf, "error\n");
   }
}

static ssize_t mode_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count){
   if (strncmp(buf,"on",count-1)==0) { mode = ON; ledOn = true; }
   else if (strncmp(buf,"off",count-1)==0) { mode = OFF; ledOn = false;}

   pr_info("Led mode changed successfully!\n");

   gpio_set_value(gpioLED, ledOn);  
   
   return count;
}



static struct kobj_attribute mode_attr = __ATTR(mode, 0664, mode_show, mode_store);

static int __init my_init(void){
   int result = 0;

   sprintf(ledName, "led%d", gpioLED);  
   pr_info("Initializing GPIO LED %s...\n", ledName);

   kobj_ref = kobject_create_and_add("cdac_led", NULL); // kernel_kobj points to /sys/cdac_edd
   if(!kobj_ref){
      pr_err("Failed to create kobject\n");
      return -ENOMEM;
   }

   // create an attr group
   result = sysfs_create_file(kobj_ref, &mode_attr.attr);
   if(result) {
      pr_err("Failed to create sysfs group\n");
      goto r_sys_grp;
   }

   result = gpio_request(gpioLED, "sysfs");          
   if (result<0)
   {
      pr_err("Error in gpio request!\n");
      goto r_gpio_req;
   }

   ledOn = true;
   gpio_direction_output(gpioLED, ledOn);   
   gpio_export(gpioLED, false);  		// export in /sys/class/gpio/...


   return 0;


r_gpio_req:
   sysfs_remove_file(kobj_ref, &mode_attr.attr);
r_sys_grp:
   kobject_put(kobj_ref);
   return -1;

}

static void __exit my_exit(void)
{

   gpio_set_value(gpioLED, 0);
   gpio_unexport(gpioLED);
   gpio_free(gpioLED);
   pr_info("GPIO %d freed up\n", gpioLED);
   sysfs_remove_file(kobj_ref, &mode_attr.attr);
   kobject_put(kobj_ref);

   printk(KERN_INFO "Good bye from %s!\n", KBUILD_MODNAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("A simple LED driver using GPIOs");
