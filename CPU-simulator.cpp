// CPU-simulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "CPU-simulator.h"
#include "ini.h"
#include <string.h>



int _tmain(int argc, char* argv[])
{
	ConfigurationStruk configuration;
	Memory memory;
	int tmp=10;

	if(argc!=2)
	{
		printf("Wronge command line arguments number!\n");
		exit(1);
	}


	if (ini_parse(argv[1], handler, &configuration) < 0) {
		printf("Can't load '%s' file\n",argv[1]);
		return 1;
	}

	printf("%X",tmp);
	//	ReadInitMemory(argv[3],&memory);

	getch();
	return 0;
}


//private function used by ini_parse
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


int WriteRegisterDumpToFile(char *file_name, RegisterDump *regdump)
{
	FILE *file=fopen(file_name,"w");
	int i;

	if (file==NULL)
	{
		printf("error in write registery dump file\n %s %s ",__FILE__,__LINE__);
		return 0;
	}

	for(i=0;i<NUMBER_OF_REGISTERS;i++)
	{
		fprintf(file,"$%d %d\n",i,regdump->reg[i]);
	}

	fclose(file);
	return 1;
}


int WriteMemoryDumpToFile(char *file_name, Memory *memory)
{
	FILE *file=fopen(file_name,"w");
	int i;

	if (file==NULL)
	{
		printf("error in write memory dump file\n %s %s ",__FILE__,__LINE__);
		return 0;
	}

	for(i=0;i<MEMORY_SIZE;i++)
	{
		if(i%8==0)
			fprintf(file,"%X ",memory->mem[i]);
		else
			fprintf(file,"\n");
	}

	fclose(file);
	return 1;
}


int ParseCMDfile(char *file_name, Memory *memory, RegisterDump *regdump)
{
	FILE *file=fopen(file_name,"w");
	char lineBuffer[MAX_LINE_SIZE];

	if (file==NULL)
	{
		printf("error in write CMD file\n %s %s ",__FILE__,__LINE__);
		return 0;
	}

	while ( fgets ( lineBuffer, sizeof lineBuffer, file ) != NULL ) 
	{
		ExecuteCMD(lineBuffer,memory, regdump);
	}

	fclose(file);
	return 1;
}


void ExecuteCMD(char *lineBuffer,Memory *memory ,RegisterDump *regdump)
{
	char *p;//iterator over the string to tokenize
	char cmd[5][10];//to store the command  line
	p=strtok(lineBuffer, " ");
	while(p!=NULL)
	{
		//TODO
	
		p = strtok (NULL, " ");
	
	}
	
}