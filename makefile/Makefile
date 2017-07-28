#this is make file
#Makefile的作用：可以使编译过程更加方便快捷，只需执行make命令即可
#简单解释一下：hello.out是目录文件，max.o、min.o、test.c是原文件，gcc max.o min.o test.c是生成hello.out的命令；
#gcc前必须用tab键，否则出错；
#下面同理
hello.out:max.o min.o test.c
	gcc max.o min.o test.c
max.o:max.c
	gcc -c max.c
min.o:min.c
	gcc -c min.c
