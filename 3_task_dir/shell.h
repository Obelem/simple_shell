#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void prompt(void);
void tokenifier(char *cmd, ssize_t line_size);
void read_cmd(char **argv, char *cmd, ssize_t line_size); 
void file_path(char **argv, char *cmd, ssize_t line_size); 

/* utilities */
int count_tok(char *cmd, char *delim);
int count_tok_char(char *token);
void add_to_argv(char **argv, char *token, int i, int n, char *delim);

/* strfunc */
char *_strncpy(char *dest, const char *src, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *str1, char* str2);
int _strncmp(char *str1, char* str2, int n);


#endif
