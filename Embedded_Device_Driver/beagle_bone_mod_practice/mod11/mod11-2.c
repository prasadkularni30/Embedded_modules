/* Interrupt handling using GPIO */

#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>       
#include <linux/kobject.h>   
#include <linux/interrupt.h>
		
// button related
static unsigned int gpioButton = 46; // P8_16
static unsigned int gpioLED1 = 60;
static unsigned int gpioLED2 = 48;
static unsigned int irqNumber;	     // mapped to gpioButton
static unsigned int numPresses = 0;

static irq_handler_t button_handler(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
	pr_info("Button press interrupt!\n");
	
	if(gpio_get_value(gpioButton))
	{
		pr_info("Rising Egde interrupt\n");
		gpio_set_value(gpioLED1,1);
		gpio_set_value(gpioLED2,0);
	}
	else
	{
		pr_info("Falling Egde interrupt\n");
		gpio_set_value(gpioLED1,0);
		gpio_set_value(gpioLED2,1);
	}

   numPresses++;

   return (irq_handler_t) IRQ_HANDLED;
}

static int __init my_init(void){
   int result = 0;

   pr_info("Setting up IRQ for GPIO %d for button\n", gpioButton);

   if (!gpio_is_valid(gpioButton))
   {
      pr_err("Invalid GPIO for button!\n");
      return -ENODEV;
   }

   gpio_request(gpioButton, "sysfs"); 
   gpio_direction_input(gpioButton);  
   
   gpio_request(gpioLED1, "led1"); 
   gpio_direction_output(gpioLED1,0);  
   
   gpio_request(gpioLED2, "led2"); 
   gpio_direction_output(gpioLED2,0);

   irqNumber = gpio_to_irq(gpioButton); 
   pr_info("GPIO %d mapped to IRQ number %d\n", gpioButton, irqNumber);

   gpio_export(gpioButton, false);  		// export in /sys/class/gpio/...
   gpio_export(gpioLED1, false);  		// export in /sys/class/gpio/...
   gpio_export(gpioLED2, false);  		// export in /sys/class/gpio/...
   
   if(gpio_set_debounce(gpioButton,200))	//to fix debouncing issue (200 is ms)
   {
	pr_err("failed to set debouncing\n");
   }
   result = request_irq(irqNumber, 
		   	(irq_handler_t) button_handler, 
			IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,	///RISING flag is for egde trigger rising and FALLING is egde trigger falling
			"my_button_handler",
			NULL);

   return result;
}

static void __exit my_exit(void)
{
   free_irq(irqNumber, NULL);

   gpio_set_value(gpioLED1,0);
   gpio_set_value(gpioLED2,0);

   gpio_unexport(gpioButton);                  
   gpio_free(gpioButton);                      
   
   gpio_unexport(gpioLED1);                  
   gpio_free(gpioLED1);                      
   
   gpio_unexport(gpioLED2);                  
   gpio_free(gpioLED2);

   pr_info("GPIO %d freed up\n", gpioButton);

   pr_info("%d button presses were detected!\n", numPresses);
   pr_info("Good bye from %s!\n", KBUILD_MODNAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC EDD <edd@cdac.gov.in>");
MODULE_DESCRIPTION("A simple interrupt driver using GPIO button");
