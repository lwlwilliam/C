### gdb概述

当程序编译完成后，它可能无法正常运行，或许程序会彻底崩溃；或许只是不能正常地运行某些功能；或许它的输出会被挂起；或许不会提示要求正常的输入。无论在何种情况下，跟踪这些问题，特别是在大的工程中，将是开发中最困难的部分，我们将学习gdb(GNU debugger)调试程序的方法，该程序是一个调试器，是用来帮助程序员寻找程序中的错误的软件。

gdb是GNU开发组织发布的一个强大的UNIX/Linux下的程序调试工具。或许，有人比较习惯图形界面方式的，像VC、BCB等IDE环境，但是在UNIX/Linux平台下做软件，gdb这个调试工具有比VC、BCB的图形化调试器更强大的功能。所谓“寸有所长，尺有所短”就是这个道理。

一般来说，gdb主要帮忙用户完成下面4个方面的功能：

1. 启动程序，可以按照用户自定义的要求随心所欲的运行程序。
2. 可让被调试的程序在用户所指定的调试的断点处停住 (断点可以是条件表达式)。
3. 当程序停住时，可以检查此时程序中所发生的事。
4. 动态地改变程序的执行环境。
5. 从上面来看，gdb和一般的调试工具区别不大，基本上也是完成这些功能，不过在细节上，会发现gdb这个调试工具的强大。大家可能习惯了图形化的调试工具，但有时候，命令行的调试工具却有着图形化工具所不能完成的功能。


### 使用gdb

gdb主要调试的是C/C++的程序。要调试C/C++的程序，首先在编译时，必须要把调试信息加到可执行文件中。使用编译器(cc/gcc/g++)的 -g 参数即可。如：

```
gcc -g helloc. -o hello
```

如果没有-g，将看不见程序的函数名和变量名，代替它们的全是运行时的内存地址。当用-g把调试信息加入，并成功编译目标代码以后，看看如何用gdb来调试。

启动gdb的方法有以下几种：

1. gdb program也就是执行文件，一般在当前目录下。
2. gdb core 用gdb同时调试一个运行程序和core文件，core是程序非法执行后，core dump后产生的文件。
3. gdb 如果程序是一个服务程序，那么可以指定这个服务程序运行时的进程ID。gdb会自动attach上去，并调试它。program应该在PATH环境变量中搜索得到。 gdb启动时，可以加上一些gdb的启动开关，详细的开关可以用gdb -help查看。下面只列举一些比较常用的参数： -symbols -s 从指定文件中读取符号表。 -se file 从指定文件中读取符号表信息，并把它用在可执行文件中。 -core -c 调试时core dump的core文件。 -directory -d 加入一个源文件的搜索路径。默认搜索路径是环境变量中PATH所定义的路径。
