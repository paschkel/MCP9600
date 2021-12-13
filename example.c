#include <stdio.h>

#include "MCP9600.h"





 
int main(void) {

int FILE_MCP9600;
 
FILE_MCP9600 = MCP9600_Init(0x60, 'K', 0);		// Address 0x60; Type-K Sensor; No Filter
	
printf("Probe Temperature: %.1f C - Ambient Temperature: %.1f C\n", MCP9600_ReadProbeTemperature(FILE_MCP9600), MCP9600_ReadAmbientTemperature(FILE_MCP9600));
	    

return 0; 
}
