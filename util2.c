#include "shell.h"

/**
 * @brief 
 * 
 * 
 */

void errors(char *str)
{
	if (strcmp(str,  "execve") == 0 )
	{
		write(1,"No such file or directory\n", 27);
	}
	else if (strcmp(str, "fork") == 0 )
	{
		write (1,"fork failed: Resource temporarily unavailable\n", 47);	
	}
}
