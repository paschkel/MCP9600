#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <wiringPi.h>
#include <errno.h>
#include <wiringPiI2C.h>

#include "MCP9600.h"




int MCP9600_Init(char adress, char type, int filter)
{
   int fd;

   if((fd = wiringPiI2CSetup(adress)) < 0 ) {
      printf("ERROR\n");    	
	  return -1;
	  }
   else {
	   
		switch( type )
			{
			case 'K':
				type = 0x00;
				break;

			case 'J':
				type = 0x01;
				break;

			case 'T':
				type = 0x02;
				break;

			case 'N':
				type = 0x03;
				break;

			case 'S':
				type = 0x04;
				break;

			case 'E':
				type = 0x05;
				break;

			case 'B':
				type = 0x06;
				break;

			case 'R':
				type = 0x07;
				break;

			default:

			}


		  if((wiringPiI2CWriteReg8(fd, 0x05,  ((type<<4) | (0x07 & filter))) ) < 0 ) 
		  printf("ERROR\n");   
		  return fd;
		}
} 

      
float MCP9600_ReadAmbientTemperature(int fd) {
	
	int result;

	if((result = wiringPiI2CReadReg16 (fd, 0x02)) < 0 ) {
      printf("MCP9600_ERROR\n");
		return -1;
	}
	else
		return (float)((0xff & (result>>8)) | (0xff00 &(result<<8))) * 0.0625;
}   

float MCP9600_ReadProbeTemperature(int fd) {
	
	int result;

	if((result = wiringPiI2CReadReg16 (fd, 0x00)) < 0 ) {
      printf("MCP9600_ERROR\n");
		return -1;
	}
	else
		return (float)((0xff & (result>>8)) | (0xff00 &(result<<8))) * 0.0625;
}
