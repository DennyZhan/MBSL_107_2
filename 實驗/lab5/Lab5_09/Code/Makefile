obj-m:=lab5.o
KERNEL_DIR = /usr/src/linux-headers-4.4.0-31-generic/


PWD := $(shell pwd)

all:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD)
clean:
	rm *.o*.ko*.mod.c
.PHONY:clean

