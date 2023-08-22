#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list
 * @var: holds
 * @next: next code
 */
typedef struct list
{
	char *var;
	struct list *next;

}list_t;

int execute_cmd(char **tok, list_t *env, int number, char **cmd);
char *no_space(char *string);
void contc(int i);
int print_prompt(char **envir);
int custom_atoi(char *s);
int exit_builtin(char **string, list_t *env, int number, char **cmd);
char *custom_stringcat(char *d, char *sr);
int cd_setenv(list_t **env, char *n, char *d);
void cd_home(list_t *env, char *cur);
int execute_cmd_cd(list_t *env, char *cur, char *d, char *string, int number);
int custom_cd (char **string, list_t *env, int number);
void *custom_realloc(void *p, unsigned int old_s, unsigned int n_s);
size_t custom_getline(char **streamer);
int custom_strncmp(char *str1, char *str2);
char *custom_strcopy(char *d, char *s);
char *custom_strdup(char *string);
int custom_strlen(char *string, int position, char delimet);
int tok_s(char *string, char delimet);
char *ign_d(char *string, char delimet);
char **custom_strtok(char *string, char *del);
char *custom_wh(char *string, list_t *env);
int custom_size(char *string, char delimet);
char **cust_tok(char *string, char *delimet);
list_t *envir_list(char **env);
int custom_envbuiltin( char **string, list_t *env);
void free_dp(char **arr);
char *custom_duplicate(char *string, int bytes);
char *custom_look_env(char *name, list_t *env);
int length_number(int numbo);
char *int_transfer(int lumbo);
size_t my_printf(list_t *liced);
list_t *node_ended(list_t **top, char *n_data);
int idx_node(list_t **top, int idx);
void free_list(list_t *listings);
char *ignorance(char *evars);
void non_inter(list_t *env);
void cannot_change(char *string, int num, list_t *env);
void invalid_num(char *string, int num, list_t *env);
void havent_found(char *string, int num, list_t *env);
int get_envir(list_t *env, char *name);
int custom_unsetenv(list_t **env, char **string);
int custom_setenv(list_t **env, char **string);
int custom_execve(char **cmd, list_t *env, int number);
void contd(int i, char *cmd, list_t *env);

#endif
