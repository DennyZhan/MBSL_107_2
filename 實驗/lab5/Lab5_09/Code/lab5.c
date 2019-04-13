#include <linux/kernel.h>
#include <linux/module.h>
static int __init tk1_hello_module_init(void)
{
    printk("lab5 install\n");
    return 0;
}
static void __exit tk1_hello_module_cleanup(void)
{
    printk("lab5 exit\n");
}
module_init(tk1_hello_module_init);
module_exit(tk1_hello_module_cleanup);
MODULE_LICENSE("GPL");

