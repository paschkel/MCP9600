#ifndef MCP9600_H
#define MCP9600_H

int MCP9600_Init(char address, char type, int filter);
float MCP9600_ReadAmbientTemperature(int fd);
float MCP9600_ReadProbeTemperature(int fd);



#endif // #define MCP9600_H