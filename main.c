#include "shell.h"

int main(void)
{
    char buffer[BUFFER_SIZE];
	char *args[BUFFER_SIZE];
    int n_read;
	char *token;
	int i;

    while (1)
    {
        _displayPrompt();
        n_read = _read(buffer, BUFFER_SIZE);
        if (n_read == 0)
        {
            printf("\n");
            break;
        }
        buffer[n_read - 1] = '\0';
		token = strtok(buffer, " ");
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;
        _execute(args[0], args);
    }

    return 0;
}