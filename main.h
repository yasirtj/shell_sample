#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void view_prompt(void);
void io_print(const char *io_msg);
void read_user_input(char *user_input);
char **tokenize_cmd(char *string, char *delimeter);
void execute_command(char **argv);
void custom_exit(int status_code, const char *err_msg);



#endif
