#ifndef text_H_
#define text_H_

char *upper_case(char str[]);
void read_file(const char *file_name, char *argumentWord);
void replace(char *line, const char *oldWord, const char *newWord);
void print_sorted_data();
#endif