#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("Dual BSD/GPL");
struct proc_dir_entry * custome_proc_node;

static ssize_t	custom_proc_read(struct file * file_pointer, 
                        char __user * userbuffer, 
                        size_t count, 
                        loff_t * offset){

    char str[] = "Aknowledge!!! \n";
    size_t len = strlen(str);
    if (*offset >=len)
        {
            return 0;
        }

    int result = copy_to_user(userbuffer,str,len);

    *offset +=len;



    printk(KERN_ALERT "custom_proc_read\n");
    return len;
}

struct proc_ops custom_proc_ops = {
    .proc_read = custom_proc_read

} ;

static int hello_init(void)
{
printk(KERN_ALERT "Hello, world\n");
printk(KERN_ALERT "Proc dir entry is started..\n");
custome_proc_node = proc_create("My_first_proc_driver", 0, NULL,&custom_proc_ops);
if (custome_proc_node == NULL)
{
    printk(KERN_ALERT "Proc dir entry is not created due to error!!!!!!!!.\n");
    return -1;
}
printk(KERN_ALERT "Proc dir entry is created.\n");
return 0;
}
static void hello_exit(void)
{
printk(KERN_ALERT "Exiting\n");
proc_remove(custome_proc_node);
printk(KERN_ALERT "Goodbye, cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
