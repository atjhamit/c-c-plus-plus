#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h>

#define PK printk(KERN_INFO "Func : [%s]\n", __FUNCTION__)

MODULE_LICENSE("GPL");

int open_op(struct inode *pinode, struct file *pfile)
{
    PK; return 0;
}

ssize_t read_op(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    PK; return 0;
}

ssize_t write_op(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    PK; return length;
}

int close_op(struct inode *pnode, struct file *pfile)
{
    PK; return 0;
}

struct file_operations char_file_op = {
	.owner = THIS_MODULE,
	.read = read_op,
	.write = write_op,
	.open = open_op,
	.release = close_op,
};

__init int char_init(void)
{
    PK;
    register_chrdev(301,"ACharDriver",&char_file_op);
    return 0;
}

void char_exit(void)
{
    PK;
    unregister_chrdev(301,"ACharDriver");
}


module_init(char_init);
module_exit(char_exit);
