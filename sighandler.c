#include "main1.h"

/**
 * sigint_handler - a function that handles signals from stdin
 * @signum: signal to handle
 *
 * Returns: Nothing
 */
void sigint_handler(int signum)
{
	(void)signum;
	sigint_received = 1;
}

/**
 * cleanup- a function to clean up after sigint has been called
 * @args: an array of words
 * @command: first command passed to execve
 * @command_copy: an array passed for tokenization
 *
 * Description: To clean all memory when EOF is met
 */
void cleanup(char **args, char *command, char *command_copy)
{
	int i;

	for (i = 0; args[i] != NULL, i++)
	{
		free(args[i]);
	}
	free(args);
	free(command_copy);
	free(command);
}
