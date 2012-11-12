

#ifndef _CPU_SIMULATOR_H
#define _CPU_SIMULATOR_H

//struct that contain the ini file parameters
typedef struct ConfigurationStruk_
{
	int addsub_delay;
	int mul_delay;
	int div_delay;
	int instruction_q_depth;
	int addsub_rs;
	int muldiv_rs;
	int load_q_depth;
	int reorder_buffer;
	int ghr_width;
	int two_threads_enabled;
	int l1_block_size;
	int l1_access_delay;
	int l1_cache_size;
	int l2_block_size;
	int l2_access_delay;
	int l2_cache_size;
	int mem_access_delay;

} ConfigurationStruk;

#define	NUMBER_OF_REGISTERS 32
typedef struct RegisterDump_
{
	int reg[NUMBER_OF_REGISTERS];
} RegisterDump;

#define MEMORY_SIZE 65536
typedef struct Memory_
{
	int mem[MEMORY_SIZE];
}Memory;


#define MAX_LINE_SIZE 50
void ReadInitMemory(char *file_name, Memory *memory);
int WriteRegisterDumpToFile(char *file_name, RegisterDump *regdump);
int WriteMemoryDumpToFile(char *file_name, Memory *memory);
int WriteExcTimeToFile(char *file_name, int time);
int WriteExcCommandNumberToFile(char *file_name, int command_number);
int ParseCMDfile(char *file_name, Memory *memory, RegisterDump *regdump);
static int handler(void* user, const char* section, const char* name,const char* value);
void ExecuteCMD(char *lineBuffer,Memory *memory ,RegisterDump *regdump);

#endif

