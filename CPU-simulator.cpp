// CPU-simulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "CPU-simulator.h"
#include "ini.h"
#include <string.h>


void ParseConfigurationFile(char *path, ConfigurationStruk *configuration);
void ReadInitMemory(char *file_name, Memory *memory);
int WriteRegisteryDumpToFile(char *file_name, RegisterDump regdump);
int WriteMemoryDumpToFile(char *file_name, Memory memory);
int WriteExcTimeToFile(char *file_name, int time);
int WriteExcCommandNumberToFile(char *file_name, int command_number);
static int handler(void* user, const char* section, const char* name,const char* value);
int _tmain(int argc, char* argv[])
{
	ConfigurationStruk configuration;
	Memory memory;


	if(argc!=2)
	{
		printf("Wronge command line arguments number!\n");
		exit(1);
	}

	
    if (ini_parse(argv[1], handler, &configuration) < 0) {
        printf("Can't load '%s' file\n",argv[1]);
        return 1;
    }

	printf("%d",configuration.ghr_width);
	//	ReadInitMemory(argv[3],&memory);

	getch();
	return 0;
}

void ParseConfigurationFile(char *path, ConfigurationStruk *configuration)
{

}


static int handler(void* user, const char* section, const char* name,
				   const char* value)
{
	ConfigurationStruk* pconfig = (ConfigurationStruk*)user;

#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
	if (MATCH("", "addsub_delay"))
	{
		pconfig->addsub_delay = atoi(value);
	}
	else if (MATCH("", "mul_delay"))
	{
		pconfig->mul_delay = atoi(value);
	}
	else if (MATCH("", "div_delay"))
	{
		pconfig->div_delay = atoi(value);
	}
	else if (MATCH("", "instruction_q_depth"))
	{
		pconfig->instruction_q_depth = atoi(value);
	}
	else if (MATCH("", "addsub_rs"))
	{
		pconfig->addsub_rs = atoi(value);
	}
	else if (MATCH("", "muldiv_rs"))
	{
		pconfig->muldiv_rs = atoi(value);
	}
	else if (MATCH("", "load_q_depth"))
	{
		pconfig->load_q_depth = atoi(value);
	}
	else if (MATCH("", "reorder_buffer"))
	{
		pconfig->reorder_buffer = atoi(value);
	}
	else if (MATCH("", "ghr_width"))
	{
		pconfig->ghr_width = atoi(value);
	}
	else if (MATCH("", "two_threads_enabled"))
	{
		pconfig->two_threads_enabled = atoi(value);
	}
	else if (MATCH("", "l1_block_size"))
	{
		pconfig->l1_block_size = atoi(value);
	}
	else if (MATCH("", "l1_access_delay"))
	{
		pconfig->l1_access_delay = atoi(value);
	}
	else if (MATCH("", "l1_cache_size"))
	{
		pconfig->l1_cache_size = atoi(value);
	}
	else if (MATCH("", "l2_block_size"))
	{
		pconfig->l2_block_size = atoi(value);
	}
	else if (MATCH("", "l2_access_delay"))
	{
		pconfig->l2_access_delay = atoi(value);
	}
	else if (MATCH("", "l2_cache_size"))
	{
		pconfig->l2_cache_size = atoi(value);
	}
	else if (MATCH("", "mem_access_delay"))
	{
		pconfig->mem_access_delay = atoi(value);
	}
	else 
	{
		return 0;  /* unknown section/name, error */
	}

	return 1;
}
