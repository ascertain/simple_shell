#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
extern char **environ;

void _displayPrompt();
int _read(char *buffer, int buffer_size);
void _execute(char *command, char **args);

#endif
