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
extern int exit_shell(int *should_exit_ptr);
struct EnvNode {
	char *name;
	char *value;
	struct ENVNODE *next;
};

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
void exit_builtin(char *command[], int *should_exit_ptr);
char custom_envbuiltin(char *command[], char **env);
void custom_memcpy(void *des, const void *sr, size_t n);
void *custom_realloc(void *p, size_t size);
ssize_t custom_getline(char **linep, size_t *n, FILE *stream);
size_t custom_strspn(const char *s, const char *chset);
char *custom_strchr(const char *s, int ch);
char *custom_strpbrk(const char *s, const char *chset);
char *custom_strtok(char *s, const char *del);
int custom_atoi(const char *s);
int custom_setenv(const char *name, const char *value, int overw);
int custom_unsetenv(const char *name);
int execute_setenv(char *args[]);
int execute_unsetenv(char *args[]);
int set_custom_env(const char *name, const char *value, int overw);
void update_or_add_env(char **env, const char *n_en, size_t n_len, int o);
void free_environment(char **env);
char *create_env_entry(const char *n, const char *v, size_t n_le, size_t v_le);
char **duplicate_environment(char **src_env);


#endif
