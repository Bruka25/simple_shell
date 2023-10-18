#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

alias_t *alias_addend(alias_t **head, char *name, char *value);
list_t *addnode_toend(list_t **head, char *dir);
void _lineptr_assign(char **lineptr, size_t *n, char *buffer, size_t b);
char *_itoa(int num);
int bk_alias(char **args, char __attribute__((__unused__)) **start);
void bk_help_all(void);
int bk_exit(char **args, char **start);
int bk_call_args(char **args, char **start, int *exe_ret);
int bk_help(char **args, char __attribute__((__unused__)) **start);
int cant_open_file(char *file_path);
int bk_check_args(char **args);
char **_environcopy(void);
int token_count(char *str, char *delim);
int error_print(char **args, int err);
char *_error126(char **args);
char *_error127(char **args);
char *err_one(char **args);
char *error_syntax2(char **args);
char *environ_err(char **args);
char *error_cd2(char **args);
char *error_exit2(char **args);
char *replace_col_dir(char *path);
void free_list_alias(alias_t *head);
char *process_id(void);
void _args_tofree(char **args, char **start);
void free_list(list_t *head);
void environ_free(void);
char *bk_get_arg(char *line, int *exe_ret);
int (*builtin_get(char *command))(char **args, char **start);
char **_environget(const char *var);
char *find_env_value(char *beginning, int len);
char *find_location(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
list_t *parse_dir(char *path);
ssize_t find_new_len(char *line);
void line_handler(char **line, ssize_t read);
int argument_handle(int *exe_ret);
void help(void);
void bk_help_exit(void);
void bk_help_cd(void);
void bk_help_setenv(void);
void bk_env_help(void);
void operate_logically(char *line, ssize_t *new_len);
void handle_signal(int sig);
int execute(char **args, char **start);
int main(int argc, char *argv[]);
int length_ofnum(int num);
void print_err(char *message);
void bk_print(char *message);
void alias_print(alias_t *alias);
int run_file_cmds(char *file_path, int *exe_ret);
void *bk_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **replace_aliases(char **args);
int bk_env(char **args, char __attribute__((__unused__)) **start);
int bk_setenv(char **args, char __attribute__((__unused__)) **start);
void alias_set(char *var_name, char *value);
int bk_run_args(char **args, char **start, int *exe_ret);
int bk_unsetenv(char **args, char __attribute__((__unused__)) **start);
char **_strtok(char *line, char *delim);
int token_length(char *str, char *delim);
void replace_vars(char **line, int *exe_ret);
void bk_unsetenv_help(void);
int bk_cd(char **args, char __attribute__((__unused__)) **start);
int argument_handle(int *exe_ret);
void bk_help_alias(void);



char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);


#endif
