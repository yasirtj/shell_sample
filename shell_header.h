#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void view_prompt(void);
void io_print(const char *io_msg);
void read_user_input(char *user_input, size_t user_input_size);
char **tokenize_cmd(char *string, char *delimeter);
void execute_command(char **argv);
char *cmd_locater(char *string_cmd);
char *_strcat(char *dest, char *src);
void custom_free(void *ptr_to_be_freed);
void custom_exit(int status_code, const char *err_msg);



#endif
