obj-m  += mod12-1.o mod12-1_led.o mod12-2.o mod12-3.o mod12-4.o mod12-5.o mod12-5_delayqueue.o
 
ifdef ARCH
  #You can update your Beaglebone path here.
  KSRC = ../linux
else
  KSRC = /lib/modules/$(shell uname -r)/build
endif
 
all:
	make -C $(KSRC)  M=$(shell pwd) modules
 
clean:
	make -C $(KSRC)  M=$(shell pwd) clean
