#include <stdio.h>
#include <stdlib.h>
#include "rle.h"

// Function to compress a file using Run-Length Encoding (RLE)
void compress_rle(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");

    if (!infile || !outfile) {
        perror("Error opening file");
        exit(1);
    }

    int current_char, last_char;
    int count = 0;

    last_char = fgetc(infile);
    if (last_char != EOF) {
        count = 1;
    }

    while ((current_char = fgetc(infile)) != EOF) {
        if (current_char == last_char) {
            count++;
        } else {
            fprintf(outfile, "%d%c", count, last_char);
            count = 1;
            last_char = current_char;
        }
    }

    if (count > 0) {
        fprintf(outfile, "%d%c", count, last_char);
    }

    fclose(infile);
    fclose(outfile);
    printf("Compression complete.\n");
}

// Function to decompress a file using Run-Length Encoding (RLE)
void decompress_rle(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");

    if (!infile || !outfile) {
        perror("Error opening file");
        exit(1);
    }

    int count;
    char character;

    while (fscanf(infile, "%d%c", &count, &character) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(character, outfile);
        }
    }

    fclose(infile);
    fclose(outfile);
    printf("Decompression complete.\n");
}
