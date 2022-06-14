#ifndef SHELL_H
#define SHELL_H
/**
 * == changes ==
 * 1. added <ctype.h> header to implement isdigit() in exit_process
 * 2. we need to make our custom isdigit() function
 * 3. changed return type of prompt(), tokenifier() and file_path() to int
 * to handle exit status
 * 4. added the exit_process() function prototype
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h> /* we need to write ours */

/* Built in global variable to help access environment variables */
extern char **environ;

int prompt(void);
int tokenifier(char *cmd, ssize_t line_size);
void read_cmd(char **argv, char *cmd, ssize_t line_size); 
int file_path(char **argv, int argc, char *cmd, ssize_t line_size); 

/* utilities */
int count_tok(char *cmd, char *delim);
int count_tok_char(char *token);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);

/* strfunc */
char *_strncpy(char *dest, const char *src, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *str1, char* str2);
int _strncmp(char *str1, char* str2, int n);

/* built-ins */
int exit_process(int argc, char **argv); /* ----> just added <----*/
int _setenv(int argc, char **argv);
int change_dir(int argc, char **argv);

#endif
