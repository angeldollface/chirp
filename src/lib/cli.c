/*
CHIRP by Alexander Abraham 
a.k.a. "Angel Dollface".
Licensed under the DSL v1.
*/

// Importing the module header.
#include "cli.h"

// Importing functions
// relevant for analysis.
#include "chirp.h"

// Import the STD lib.
// functions.
#include <stdio.h>
#include <string.h>


// This function contains Chirp's light
// CLI.
void cli(int argc, char* argv[]){
    char err_msg[] = "Unrecognized combination of arguments.";
    int sec_weight = 3;
    int arabic_weight = 3;
    int special_weight = 2;
    int cutoff = 12;
    if (argc == 2){
       if (strcmp(argv[1], "version") == 0){
            printf("Chirp v.0.2.0\nby Angel Dollface.\n");
       }
       else if (strcmp(argv[1], "help") == 0){
            printf("help    display this message\nversion display version info\npwd     test a password\n");    
       }
       else {
            printf("%s\n", err_msg);
       }
    }
    else if (argc == 3){
        if (strcmp(argv[1], "pwd") == 0 && str_is_empty(argv[2]) != 1){
            int result= password_strength(
								argv[2], 
								sec_weight, 
								arabic_weight, 
								special_weight
						);
						int sec_status = is_secure(
								argv[2],
								sec_weight,
								arabic_weight,
								special_weight,
								cutoff
						);
            printf("Password: %s\n", argv[2]);
            printf("Score: %d\n", result);
            printf("Status: %d\n", sec_status);
        }
        else {
            printf("%s\n", err_msg);
        }
    }
    else {
        printf("%s\n", err_msg);
    }
}

