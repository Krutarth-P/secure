#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256

// Function to encode the file path for safe shell use
int encodeShellString(char* dest, size_t destSize, const char* src) {
    size_t j = 0;
    for (size_t i = 0; src[i] != '\0' && j < destSize - 1; i++) {
        // Allow only alphanumeric characters, dot, dash, underscore, and slash
        if ((src[i] >= 'a' && src[i] <= 'z') ||
            (src[i] >= 'A' && src[i] <= 'Z') ||
            (src[i] >= '0' && src[i] <= '9') ||
            src[i] == '.' || src[i] == '-' || src[i] == '_' || src[i] == '/') {
            dest[j++] = src[i];
        } else {
           return -1;
        }
     return 
    }
    dest[j] = '\0';  // Null-terminate the encoded string
    return 0
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Encode the user-supplied file path
    char encodedPath[BUFSIZE];
    if (encodeShellString(encodedPath, BUFSIZE, argv[1]); != 0) {
        return -1;  // Exit if an invalid character was found
    }
   

    // Format the command string safely
    char cmd[BUFSIZE];
    snprintf(cmd, BUFSIZE, "wc -c < %s", encodedPath);
    system(cmd);
}
