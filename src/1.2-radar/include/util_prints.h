/**
 * \file util_prints.h 
 * \brief Benchmark #1.2  Radar data processing
 * \author Marc Sole (BSC)
 */

#ifndef UTIL_PRINTS_H_
#define UTIL_PRINTS_H_

#include "benchmark.h"

#define BENCHMARK_NAME "============ OBPMark #1.2 Radar Image Processing ============" 
#define BENCHMARK_ID "1.2"
#define BOOL_PRINT(a) ((a) ? ("True"): ("False"))


struct print_info_data_t
{
	unsigned int w_size;
    unsigned int h_size;
    unsigned int num_patch;
    unsigned int ml_factor;
    unsigned int out_width;
    unsigned int out_height;
    bool csv_mode;
    bool extended_csv_mode;
    bool print_output;
    bool database_mode;
    bool verbose_print;
    bool random_data;
    char *input_folder;
    char *output_file;
    bool no_output_file;
};

void print_device_info(
    print_info_data_t *print_info_data,
    char *device_name
    );

void print_benchmark_info(
    print_info_data_t *print_info_data
    );


void print_execution_info(
    print_info_data_t *print_info_data,
    bool include_memory_transfer,
    long int timestamp,
    float host_to_device_time,
    float execution_time,
    float device_to_host_time
    );


#endif // UTIL_PRINTS_H_
