#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 1024
extern char **environ;

void my_puts(const char *str);
void my_printf(const char *format, ...);
void execute_cmd(char *command[], char *(*custom_getenv)(const char *));
size_t _stringcat(char *d, size_t d_size, const char *sr);
size_t custom_strlen(const char *str);
char *strcopy(char *d, const char *s);
char *c_strdup(const char *str);
void execute_absolute_path(char *command[]);
char *custom_getenv(const char *name);
int custom_strncmp(const char *str1, const char *str2, size_t n);
void exit_builtin(char *command[]);
char custom_envbuiltin(char *command[], char **env);

#endif
