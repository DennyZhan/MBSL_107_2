MODULE_NAME = GPIO
obj-m = $(MODULE_NAME).o
KERNEL_DIR = /usr/src/linux-headers-4.4.0-31-generic/
PWD = $(shell pwd)

all: $(obj-m).ko write read
$(obj-m).ko:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD)
write:
	gcc write.c -o write
read: 
	gcc read.c -o read
clean:
	rm *.o *.ko *.mod.c
.PHONY: clean

