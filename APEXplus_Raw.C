#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a line contains "0x" or "WAIT"
int is_valid_line(const char *line) {
    return (strstr(line, "0x") || strstr(line, "WAIT"));
}
// Function to remove comments starting with "//" unless it's a "// Read: 0x" line
void remove_comments(char *line) {
    char *comment_start = strstr(line, "//");
    char *comment_read = strstr(line, "// Read: 0x");
    if (comment_start) {
        if (!comment_read) {
            *comment_start = '\0'; 
        } }
   }
int main() {
    FILE *inputFile = fopen("Afe79xxPg1Raw.txt", "r");
    FILE *outputFile = fopen("Afe79xxPg1Raw_sample_withoutCRLF.txt", "w");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        remove_comments(buffer);// Remove comments from the line
        if (is_valid_line(buffer)) {{// Remove trailing newline character
            char *newline = strchr(buffer,'\n');
            if (newline) {
                *newline = '\0';
            }    // Write the processed data to the output file// Write the processed data to the output file
            fputs(buffer, outputFile);
             fputc('\n', outputFile); // Add LF (Line Feed) to each line
        }}
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Data extracted from Afe79xxPg1Raw.txt and written to Afe79xxPg1Raw_sample_withoutCRLF.txt.\n");

    return 0;
}
