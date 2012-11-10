// CPU-simulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "CPU-simulator.h"
#include "ini.h"
#include <string.h>
#include<conio.h>
#include "utils.h"






int _tmain(int argc, char* argv[])
{
	ConfigurationStruk configuration;
	Memory memory;
	if(argc!=2)
	{
		printf("Wronge command line arguments number!\n");
		exit(1);
	}

    if (ParseConfigurationFile(char *argv[1], ConfigurationStruk *configuration))
	{
        printf("Can't load '%s' file\n",argv[1]);
        return 1;
    }

	
	//	ReadInitMemory(argv[3],&memory);
	printf("%d\n", configuration.ghr_width);
	getch();
	return 0;
}


