/*Kernel module for setting a size of byte*/
#define pr_fmt(fmt)	KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/memory.h>
// #include <linux/slab.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Nishant Thosar");
MODULE_DESCRIPTION("A simple module to allocate and free memory using kmalloc");

static void *buffer;
static size_t buffer_size = PAGE_SIZE; // Allocate one page of memory	//for 1024 byte change

static int __init my_module_init(void) {
  buffer = kmalloc(buffer_size, GFP_KERNEL); // Allocate memory with kmalloc
  // memset(buffer, 0, sizeof(buffer)); // to set the allocated memory with zero. (We don't need this if we are using kmalloc).
  if (!buffer) {
    printk(KERN_ERR "Failed to allocate memory\n");
    return -ENOMEM;
  }

  printk(KERN_INFO "Allocated memory at: %p\n", buffer);
  return 0;
}

static void __exit my_module_exit(void) {
  if (buffer) {
    kfree(buffer); // Free the memory allocated by kmalloc
    printk(KERN_INFO "Freed memory\n");
  }
}

module_init(my_module_init);
module_exit(my_module_exit);
