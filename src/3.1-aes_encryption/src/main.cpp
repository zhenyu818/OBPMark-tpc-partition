/**
 * \file main.cpp
 * \author Marc Sole Bonet (BSC)
 * \brief OBPMark Benchmark #3.1 AES Compression main file.
 */
#include "obpmark.h"

#include "benchmark.h"
#include "device.h"

/* Utility headers */
#include "util_arg.h"
#include "util_data_files.h"
#include "util_data_rand.h"

//Print data has hexadecimal
void print_data(uint8_t data[], unsigned int data_size){
    printf("0x");
    for(int i = 0; i<data_size; i++) {
        printf("%02x",data[i]);
    }
}


void init_benchmark(
        uint8_t *input,
        uint8_t *key,
        uint8_t *iv,
        uint8_t *out,
        unsigned int data_length,
        unsigned int key_size,

        long int timestamp,
        print_info_data_t *benchmark_info
        )
{
    /* Init constant arrays */
    uint8_t sbox[256] = SBOX_INIT;
	uint8_t rcon[11] = RCON_INIT;

    /* Allocate memory for host data */
    AES_time_t *t = (AES_time_t *)malloc(sizeof(AES_time_t));
    AES_data_t *AES_data =  (AES_data_t*) malloc(sizeof(AES_data_t));

	char device[100] = "";
    
    // generate output filename that is output_<k_size>_<d_size>_IMPLEMENTATION_NAME_FILE.bin
    char output_filename[100] = "output_";
    char d_size_str[10];
    char k_size_str[10];
    // generate output filename
    sprintf(d_size_str, "%d", data_length);
    sprintf(k_size_str, "%d", key_size);
    strcat(output_filename, k_size_str);
    strcat(output_filename, "_");
    strcat(output_filename, d_size_str);
    strcat(output_filename, "_");
    strcat(output_filename, IMPLEMENTATION_NAME_FILE);
    strcat(output_filename, ".bin");
    char *output_file = (char*) output_filename;
    benchmark_info->output_file = output_file;
    


	init(AES_data, t, 0, DEVICESELECTED, device);

	print_device_info(benchmark_info, device);
	print_benchmark_info(benchmark_info);

    /* Initialize memory on the device and copy data */
    if(!device_memory_init(AES_data, key_size, data_length)){
	    printf("Error initializing memory\n");
        return;
    }
    copy_memory_to_device(AES_data, t, key, input, iv, sbox, rcon);

    /* Run the benchmark, by processing the full frame list */
    process_benchmark(AES_data, t);

    /* Copy data back from device */
    copy_memory_to_host(AES_data, t, out);

    /* Get benchmark times */
	get_elapsed_time(t, benchmark_info, timestamp);

	if(benchmark_info->print_output)
    {
        print_data(out, data_length);
    }
	else 
    {
		// write the output image to a file call "output.bin"
        if (!benchmark_info->no_output_file)
        {
            frame8_t *output_frame = (frame8_t*) malloc(sizeof(frame8_t));
            output_frame->w = data_length;
            output_frame->h = 1;
            output_frame->f = out;
            int result = write_frame8(output_file, output_frame, 0);
			if (result == 1 && !benchmark_info->csv_mode && !benchmark_info->database_mode)
			{
				printf("Done. Outputs written to %s\n", output_file);
			}
		}
    }

    /* Clean and free device object */
    clean(AES_data, t);
}