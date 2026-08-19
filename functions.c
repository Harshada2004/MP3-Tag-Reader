#include "mp3_header.h"
#include<stdlib.h>

void tag_to_name(char *tag)             // Function to display tag name
{
    // Comapare tag and print corresponding field name
    if(strcmp(tag, "TIT2") == 0)
        printf("Title\t: ");
    else if(strcmp(tag, "TPE1") == 0)
        printf("Artist\t: ");
    else if(strcmp(tag, "TALB") == 0)
        printf("Album\t: ");
    else if(strcmp(tag, "TYER") == 0)
        printf("Year\t: ");
    else if(strcmp(tag, "TCON") == 0)
        printf("Music\t: ");
    else if(strcmp(tag, "COMM") == 0)
        printf("Comment\t: ");
    else
       printf("Invalid");
}

void print_tag_data(FILE *fp, int size)     // Function to print frame content
{
    char *content = malloc(size);           // Dynamically allocate memory for content
    if(content == NULL)                     // Check memory allocation
    {
        perror("Memory Error");
        return;
    }

    fread(content, 1, size, fp);        // Read frame content from file
    printf("%s\n", content + 1);        // Skip encoding byte
    free(content);                      // Free the memory
}

// -------------- VIEW FUNCTION --------------
void view(struct MP3 *mp3, int argc, char *argv[])
{                                                       // Display heading
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("                                    MP3 TAG READER AND EDITOR FOR ID3v2                     \n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    
    mp3->org_mp3_fptr = fopen(mp3->mp3_filename, "rb");     // Open mp3 file in read mode
    if(mp3->org_mp3_fptr == NULL)                           // Check file opened or not
    {
        printf("Error opening file\n");
        return;
    }

    // --------------Check ID3 Header------------
    char id[4] = {0};                       // Buffer to store ID3 identifier
    fread(id, 1, 3, mp3->org_mp3_fptr);     // Read first 3 bytes
    if(strcmp(id, "ID3") != 0)              // Compare with "ID3"
    {
        printf("Not a valid MP3 file\n");
        fclose(mp3->org_mp3_fptr);
        return;
    }
    printf("Valid MP3 file\n\n");           // MP3 validation successful

    // Skip remaining bytes of 10-byte header
    fseek(mp3->org_mp3_fptr, HEADER_SIZE - 3, SEEK_CUR);
    for(int i = 0; i < 6; i++)      // Loop to Read frames
    {
        char tag[5] = {0};          // Buffer to store frame tag
        fread(tag, 1, 4, mp3->org_mp3_fptr);    // 
        if(tag[0] == 0)         // If first byte is 0, it indicates end of frames
            break; // Exit loop

        int content_size; // Variable to store content size

        
        fread(&content_size, 4, 1, mp3->org_mp3_fptr); // Read 4 bytes for size

        
        toggle_endianess(mp3, &content_size); // Convert from BE to LE

        
        fseek(mp3->org_mp3_fptr, 2, SEEK_CUR); // Skip 2 bytes for flags

        
        tag_to_name(tag); // Convert tag to readable name and print

        
        print_tag_data(mp3->org_mp3_fptr, content_size);  // Read and print frame content
    }
    fclose(mp3->org_mp3_fptr);  // Close the file after reading

    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("-----------------------------------DETAILS DISPLAYED SUCESSFULLY----------------------------------------------\n");
    // Display Success message
}