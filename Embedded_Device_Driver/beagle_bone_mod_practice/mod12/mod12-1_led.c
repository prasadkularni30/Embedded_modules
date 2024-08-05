/* Tasklet example */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>       
#include <linux/kobject.h>   
#include <linux/interrupt.h>
	
// button related
static unsigned int gpioButton = 46; // P8_16
static unsigned int gpioLED1 = 60;    // P9_12
static unsigned int gpioLED2 = 48;    // P9_12
static unsigned int irqNumber;	     // mapped to gpioButton
static unsigned int numPresses = 0;

// tasklet related
static struct tasklet_struct my_tasklet;
static char tasklet_data[] = "Tasklet data ";

static void my_tasklet_func(unsigned long data)
{
   numPresses++;
   if( gpio_get_value(gpioButton) )
   {
	   gpio_set_value(gpioLED1,1);
	   gpio_set_value(gpioLED2,0);
   }
   else
   {
	   gpio_set_value(gpioLED1,0);
	   gpio_set_value(gpioLED2,1);
   }
   pr_info("In tasklet: data = %s, numPressed = %d\n", (char *)data, numPresses);
}

static irq_handler_t button_handler(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
   pr_info("In button press interrupt!\n");

   pr_info("Scheduling tasklet...\n");
   tasklet_schedule(&my_tasklet);

   pr_info("Exiting interrupt handler\n");
   
   return (irq_handler_t) IRQ_HANDLED;
}

static int __init my_init(void){
   int result = 0;

   pr_info("Setting up IRQ for GPIO %d for button\n", gpioButton);

   if ((!gpio_is_valid(gpioButton)) || (!gpio_is_valid(gpioLED1)) || (!gpio_is_valid(gpioLED2)) )
   {
      pr_err("Invalid GPIO for button!\n");
      return -ENODEV;
   }


   gpio_request(gpioButton, "sysfs"); 
   gpio_direction_input(gpioButton);  
   irqNumber = gpio_to_irq(gpioButton); 
   pr_info("GPIO %d mapped to IRQ number %d\n", gpioButton, irqNumber);
   gpio_export(gpioButton, false);  		// export in /sys/class/gpio/...
  
   gpio_set_debounce(gpioButton,200);		//debounicng
  
   gpio_request(gpioLED1, "LED1"); 
   gpio_direction_output(gpioLED1,0);  
   gpio_export(gpioLED1, false);  		// export in /sys/class/gpio/...

   gpio_request(gpioLED2, "LED2"); 
   gpio_direction_output(gpioLED2,0);  
   gpio_export(gpioLED2, false);  		// export in /sys/class/gpio/...
						
   tasklet_init(&my_tasklet, my_tasklet_func, (unsigned long) &tasklet_data);

   result = request_irq(irqNumber, 
		   	(irq_handler_t) button_handler, 
			IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING ,
			"my_button_handler",
			NULL);

   return result;
}

static void __exit my_exit(void)
{
   tasklet_kill(&my_tasklet);
   pr_info("Tasklet killed\n");

   free_irq(irqNumber, NULL);
   gpio_unexport(gpioButton);                  
   gpio_free(gpioButton);                      
   pr_info("GPIO %d freed up\n", gpioButton);

   gpio_unexport(gpioLED1);                  
   gpio_free(gpioLED1);                      
   pr_info("GPIO %d freed up\n", gpioLED1);
   
   gpio_unexport(gpioLED2);                  
   gpio_free(gpioLED2);                      
   pr_info("GPIO %d freed up\n", gpioLED2);

   pr_info("Good bye from %s!\n", KBUILD_MODNAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("Tasklet example");
