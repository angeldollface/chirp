/*
CHICO by Alexander Abraham 
a.k.a. "Angel Dollface".
Licensed under the DSL v1.
*/

// Importing the module
// header.
#include "chirp.h"

// Importing the STD
// lib. functions.
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


// A structure to hold
// information about
// the analysis of a
// password.
struct SecurityInfo {
    int score;
    int is_secure;
};

// This function creates a new instance of the
// "SecurityInfo" structure.
struct SecurityInfo create_new(int score, int is_secure){
    struct SecurityInfo info;
    info.score = score;
    info.is_secure = is_secure;
    return info;
}

// This function takes in analysis parameters and
// returns the results of this analysis as an instance
// of the "SecurityInfo" structure.
struct SecurityInfo get_analysis_results(
    char pwd[], 
    int sec_weight, 
    int arabic_weight, 
    int special_weight,
    int cutoff
){
    struct SecurityInfo result;
    int score = password_strength(
        pwd, 
        sec_weight, 
        arabic_weight, 
        special_weight
    );
    result.score = score;
    if (score > cutoff == 0){
        result.is_secure = 0;
    }
    else {
        result.is_secure = 1;
    }
    return result;
}

// This function returns the position of
// a letter in the alphabet.
int get_char_pos(char letter){
    int result = 0;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++){
        if (alphabet[i] == letter){
            result = i;
        }
        else {}
    }
    return result;
}

// This function returns the distance between
// two letters in the alphabet.
int get_char_space(char one, char two){
    int one_pos = get_char_pos(one);
    int two_pos = get_char_pos(two);
    int result = one_pos - two_pos;
    if (result < 0){
        result = result * (-1);
    }
    else {}
    return result;
}


// This function checks
// whether a character
// is an integer or not.
int is_int(char subject){
   int result = 1;
        if (isdigit(subject)){
            result = 0;
        }
        else {}
    return result;
}

// This function returns the distance between
// two numbers.
int get_num_space(char one, char two){
    int result = 0;
    if (is_int(one) == 0 && is_int(two) == 0){
        int one_conv = one - '0';
        int two_conv = two - '0';
        result = one_conv - two_conv;
        if (result < 0){
            result = result * (-1);
        }
        else {}
    }
    return result;
}

// This function checks whether
// the supplied character is a 
// letter or not.
int is_letter(char character){
    int result = 1;
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++){
        if (alphabet[i] == character){
            result = 0;
        }
        else {}
    }
    return result;
}

// This function checks the type
// of character supplied.
const char* char_type(char character){
    char *result = "int";
    if (is_int(character) == 0){}
    else if (is_letter(character) == 0){
        result = "letter";
    }
    else {
        result = "special";
    }
    return result;
}

// This function computes the strength of a password
// and returns it.
int password_strength(
    char pwd[], 
    int sec_weight, 
    int arabic_weight, 
    int special_weight
){
    int result = 0;
    for (int i = 0; i < strlen(pwd); i++){
        char current = pwd[i];
        const char *curr_type = char_type(current);
        if (i == 0){}
        else {
            char previous_char = pwd[i-1];
            const char *previous_type = char_type(previous_char);
            if (strcmp(curr_type, "letter") == 0 && strcmp(previous_type, "letter") == 0){
                int char_space = get_char_space(previous_char, current);
                if (char_space > sec_weight){
                    result = result + arabic_weight;
                }
                else {}
            }
            else if (strcmp(curr_type, "special") == 0 && strcmp(previous_type, "special") == 0){
                result = result + special_weight;
            }
            else if (strcmp(curr_type, "int") == 0 && strcmp(previous_type, "int") == 0){
                int num_space = get_num_space(previous_char, current);
                if (num_space > sec_weight){
                    result = result + arabic_weight;
                }
            }
            else {}
        }

    }
    return result;
}

// This function checks whether a password is secure
// depending on the cutoff score and the actual score
// it received.
int is_secure(
    char pwd[], 
    int sec_weight, 
    int arabic_weight, 
    int special_weight, 
    int cutoff
){
    int result = 0;
    int score = password_strength(pwd, sec_weight, arabic_weight, special_weight);
    if (score > cutoff){
        result = 1;
    }
    else {}
    return result;
}

// This function checks
// whether a string is an
// empty string.
int str_is_empty(char str[]){
    int result = 1;
    if (strlen(str) != 0){
        result = 0;
    }
    else {}
    return result;
}
