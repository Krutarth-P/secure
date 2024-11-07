#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256

//function to validate and escape characters
int validate_path(const char* src) {
    // Characters generally invalid in file paths
    const char* invalid_chars = "!\"#$&'()*;<>?[\\]^`{|}~";
    
    // Loop through each character in the source string
    for (size_t i = 0; src[i] != '\0'; i++) {
        // If an invalid character is found, return an error
        if (strchr(invalid_chars, src[i]) != NULL) {
            fprintf(stderr, "Invalid character detected in file path.\n");
            return -1;
        }
    }
    return 0;
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Validate the file path
    if (validate_path(argv[1]) != 0) {
        return -1;  // Exit if an invalid character was found
    }

    char cmd[BUFSIZE];
    int len = snprintf(cmd, BUFSIZE, "wc -c < '%s'", argv[1]);
    system(cmd);
}
