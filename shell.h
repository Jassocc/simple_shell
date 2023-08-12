#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#define MAX_INPUT_SIZE 256

void my_puts(const char *str);
void my_printf(const char *format, ...);
void execute_cmd(char *command[]);
size_t _stringcat(char *d, size_t d_size, const char *sr);
size_t custom_strlen(const char *str);
char *strcopy(char *d, const char *s);

#endif
