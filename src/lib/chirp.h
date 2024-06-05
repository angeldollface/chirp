/*
CHIRP by Alexander Abraham 
a.k.a. "Angel Dollface".
Licensed under the DSL v1.
*/

#ifndef CHIRP_H
#define CHIRP_H

extern int is_int(char subject);
extern int is_letter(char character);
extern int is_secure(char pwd[], int sec_weight, int arabic_weight, int special_weight, int cutoff);
extern int get_char_pos(char letter);
extern int get_num_space(char one, char two);
extern int get_char_space(char one, char two);
extern struct SecurityInfo;
extern const char* char_type(char character);
extern int password_strength(char pwd[], int sec_weight, int arabic_weight, int special_weight);
extern struct SecurityInfo create_new(int score, int is_secure);
extern struct SecurityInfo get_analysis_results(char pwd[], int sec_weight, int arabic_weight, int special_weight, int cutoff);


#endif
