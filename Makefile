
CC=$(CROSS_COMPILE)mips-openwrt-linux-gcc  -g

TARGET=serialib

serialib.o: serialib.c
	$(CC) -c serialib.c

serialib: serialib.o
	$(CROSS_COMPILE)ar rcs lib$(TARGET).a serialib.o

install: $(TARGET)
	install lib$(TARGET).a /usr/lib/lib$(TARGET).a
	install *.h /usr/include/

example: example.c $(TARGET)
	$(CC) example.c -lserialib  -std=c99 -L. -I. -o example

example-write: example-write.c $(TARGET)
	$(CC) example-write.c -lserialib -L. -I. -o example-write


clean:
	rm -rf example *.o *.a


