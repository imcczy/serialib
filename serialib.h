
#ifndef _SERIALIB_H
#define _SERIALIB_H

#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <fcntl.h> 
#include <stdio.h>

typedef struct serial_s {
	speed_t baud;
	char* port;
	int fd;
} serial;

int serial_open(serial **s, char* port, const unsigned int baud);
int serial_read_char(serial *s, char *p);
int serial_read(serial *s, char *buf, unsigned int len);
int serial_write_char(serial *s, char p);
int serial_write(serial *s, char* str);


#endif
