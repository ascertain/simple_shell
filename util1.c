#include "shell.h"

/**
 *
 *
 */

void _displayPrompt()
{
    printf("Simple_shell> ");
    fflush(stdout);
}

int _read(char *buffer, int buffer_size)
{
    int n_read;
    n_read = read(STDIN_FILENO, buffer, buffer_size);
    if (n_read == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }
    return n_read;
}

void _execute(char *command, char **args)
{
    pid_t c_pid;

    if (access(command, F_OK) == 0)
    {
        c_pid = fork();
        if (c_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        } 
        else if (c_pid == 0)
        {
            if (execve(command, args, environ) == -1) {
                perror(command);
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        perror(command);
    }
}