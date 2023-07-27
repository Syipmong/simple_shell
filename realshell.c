#include "main1.h"
#include "shell1.h"

/**
 * main - Entry to simple shell with CLI features
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: Success (0) or (1) for failure
 */
int main(int ac, char *argv[])
{
	int interactive_mode = isatty(STDIN_FILENO);
	char *command = NULL, *command_copy = NULL;
	size_t command_len = 0;
	ssize_t nread;
	char **args = NULL;
	(void)argv;
	(void)ac;

	while (1)
	{
		if (interactive_mode)
			prompt("cisfun$ ");
		nread = getline(&command, &command_len, stdin);
		if (nread == -1)
		{
			if (interactive_mode)
				perror("Error reading line");
			exit(0);
		}
		if (nread > 0 && command[nread - 1] == '\n')
			command[nread - 1] = '\0';
		command_copy = malloc(nread);
		strcpy(command_copy, command);
		args = split_commands(command_copy, " \n\t\r");
		if (_strcmp(args[0], "exit") == 0)
		{
			break;
		}
		else if (_strcmp(args[0], "env") == 0)
			print_environment();
		else
		{
			execute_command(args);
		}
	}
	freewords(args);
	free(command_copy);
	free(command);
	return (0);
}
