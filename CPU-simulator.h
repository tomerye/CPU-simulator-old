

#ifndef _CPU_SIMULATOR_H
#define _CPU_SIMULATOR_H


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
typedef int RegisterDump;
typedef int Memory;




#endif
