#include "main1.h"


/**
 * execute_command - a function that executes commands
 * @argv: an array of commands
 *
 * Return: Nothing
 */
void execute_command(char **argv)
{
	char *command = NULL, *main_command = NULL;
	pid_t pid;
	int status;

	if (argv)
	{
		command = argv[0];
		main_command = get_env(command);
	}
	if (main_command == NULL)
	{
		perror("No such file");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("./shell");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(main_command, argv, NULL) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
