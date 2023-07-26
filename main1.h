#ifndef MAIN1_H
#define MAIN1_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>

extern char **environ;

char **split_commands(char *str, char *delim);
void prompt(char *prompt);
void execute_command(char **argv);
char *get_env(char *command);
void freewords(char **commands);
void print_environment(void);
#endif
