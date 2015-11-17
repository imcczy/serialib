#include <stdio.h>
#include "serialib.h"

int main(void)
{
	serial *s;
	if (serial_open(&s, "/dev/ttyUSB0", 115200) == 0){
		printf("Port opened.\n");

	} else {
		printf("Problem with port opening\n");
		return -1;
	}
	printf("%s -> %d\n", s->port, s->fd);
	system("sleep 2");
	
	char buffer[21];
	char data[8] = {0,0,0,0,0,0,0,0};
	int index = 0;
	serial_read(s, buffer, 21);

	for (int i = 0; i < 12; ++i){
        if ((int)buffer[i] == -86 && (int)buffer[i+7] == -1)
        {
        	index = i;
        	break;
        }
	}
	for (int i = 0; i < 8; ++i)
	{
		data[i]=(int)buffer[index+i];
		//printf("%d ",data[i]);
		//printf("\n");
	}
	double temperatrue = 0;
	double humidity = 0;
	temperatrue = (data[2]*256 + data[3]) / 100.00;
	humidity = (data[4]*256 + data[5]) / 100.00;
	//printf("%f,%f\n", temperatrue,humidity);
	FILE *fp;
	fp = fopen("data.txt","w");
	fprintf(fp,"[{ \"Name\":\"T\", \"Value\":\"%.2f\" }, { \"Name\":\"H\", \"Value\":\"%.2f\" }]\n", temperatrue,humidity);
	return 0;
}

