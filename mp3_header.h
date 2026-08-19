#ifndef MP3_HEADER_H        // Prevents multiple inclusion of header files
#define MP3_HEADER_H

#include <stdio.h>          // For FILE operations
#include <string.h>         // For String handling functions

#define VIEW 	1           // Macro for VIEW operation
#define EDIT 	2           // Macro for EDIT operation
#define HEADER_SIZE 10      // ID3 header size is 10 bytes
struct MP3                  // Structure to store MP3 details
{
    char *mp3_filename;     // Stores MP3 file name
    FILE *org_mp3_fptr;     // File ptr for ORG mp3 file
    FILE *dup_mp3_fptr;     // File ptr for duplicate mp3 file
};

int validate_cla(int argc, char *argv[], struct MP3 *mp3);  // Function to validate CLA arguments
void view(struct MP3 *mp3, int argc, char *argv[]);         // Function to VIEW MP3 tag contents
void edit(struct MP3 *mp3, int argc, char *argv[]);         // Function to EDIT MP3 tag contents
void toggle_endianess(struct MP3 *mp3, int *size);          // Function to convert BIG Endian to LITTLE Endian
void print_tag_data(FILE *fp, int size);                    // Function to print frame contents
void tag_to_name(char *);                                   // Function to convert tag to readable name

#endif