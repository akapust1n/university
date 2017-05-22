obj-m += rw.o

BUILD = make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd)

all:
	$(BUILD) modules

clean:
	$(BUILD) clean
