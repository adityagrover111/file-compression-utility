#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rle.h"

void print_usage() {
    printf("Usage: ./compressor [compress/decompress] [input_file] [output_file]\n");
    printf("Commands:\n");
    printf("  compress - Compress a file using RLE\n");
    printf("  decompress - Decompress a file using RLE\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    char *command = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    if (strcmp(command, "compress") == 0) {
        compress_rle(input_file, output_file);
    } else if (strcmp(command, "decompress") == 0) {
        decompress_rle(input_file, output_file);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}
