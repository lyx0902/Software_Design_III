# Software_Design_III
南京理工大学软件课程设计(III)——2024
**《软件课程设计III》过程记录**
图片内容见仓库中的pdf
刘宇翔(922106840127),庄明哲(921106840139)
一、	虚拟机&路由器配置与XShell连接、工具链&系统编译
1.虚拟机基础属性配置
2.XShell配置无需密码登录虚拟机(SSH)与路由器(telnet)
在这里路由器的IP地址采用的是购买时已刷机后的斐讯路由器固件的配置IP：192.168.2.1，同时通过桥接模式获取IP地址建立起无需账户密码的SSH连接。
连接成功的配置XShell界面
虚拟机：
可以看到通过输入ifconfig命令可以看到其ip地址：192.168.2.141。
路由器：
可以看到，路由器的账户密码默认设置为admin，通过telnet形式连接。同时，我们也可以通过ifconfig命令查询网络配置。
3.编译工具链
根据参考文档配置对应的配置文件，中间补足了文档中步骤出现缺失的相关库配置文件，例如libtools。经过配置三个gcc compiler完成工具链的编译。
4.路由器配置文件下载与编译系统
经闲鱼购买的小米路由宝发货时已刷入斐讯路由器的breed，因此后续配置文件下载与系统编译均以此为环境执行。
通过查询对应的固件配置，我们得到本路由器固件版本，并进入对应的固件提供官网进行配置文件寻找与下载并存入以下文件夹（通过Xftp实现）。
我们使用的是RT-N56U的kernel-3.4.x.config文件与n56u.config文件，路径如下：https://bitbucket.org/padavan/rt-n56u/src/master/，包括./boards与./templates文件夹中的相关文件。
通过Xftp将配置文件存入./build_firmware.sh所需的路径：
	执行./build_firmware.sh，经过二十多分钟成功编译系统
通过提示信息可以看到生成系统位于trunk/images/RT-N56U_3.4.3.9L-100.trx，成功编译系统，可以在文件目录中找到。
二、	内核模块编译，在系统日志中体现
1.	hello_module.c文件
2.	Kconfig
3.	Makefile
4.	路径说明与运行后的系统日志呈现结果
路径说明：/root/padavan-ng/trunk/linux-3.4.x/drivers/misc/SD3
系统日志：
三、	应用模块编译，在系统内指定文件中有结果显示
1.	main.c
2.	Makefile
3.	路径说明与运行后的呈现结果
路径：/root/padavan-ng/trunk/user/SD3
四、 核心文件添加注释画出大体调度/分配流程
在本问题中，我们选择trunk/linux-3.4.x/mm/page_alloc.c 来进行注释的添加与对应函数调度流程图。page_alloc.c是内存管理相关的一个核心文件，控制着系统对应的内存管理。
由于代码过长，见附件./Task4/page_alloc.c.
我们使用Understand软件构造对应的函数调用流程图，如下：
	完整函数调用流程图见附件./Task4/ Calls&&CalledBy-page_alloc-c.pdf
