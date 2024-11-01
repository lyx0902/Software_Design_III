// 引入相关内核头文件
#include <linux/module.h>

// 内核模块信息，包括许可证、作者、描述和版本等
MODULE_LICENSE("MIT");
MODULE_AUTHOR("Liu Yuxiang && Zhuang Mingzhe");
MODULE_DESCRIPTION("kernel module");

// 内核模块参数，加载时指定或者动态指定，以此控制模块行为
static char *name = "Liu Yuxiang && Zhuang Mingzhe";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "Whom this module say hello to");


// 初始化函数，在加载时调用，分配资源准备执行环境
// 这里只是往内核日志输出一行记录
static int __init hello_init(void)
{
    printk(KERN_INFO "Hello %s\n", name);
    return 0;
}


// 清理函数，在卸载时调用，回收资源销毁执行环境
static void __exit hello_exit(void)
{
    printk(KERN_INFO "See you %s", name);
}

// 登记初始化函数及清理函数
module_init(hello_init);
module_exit(hello_exit);