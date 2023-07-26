#include "main1.h"
#include "shell1.h"

/**
 * print_environment - a program that prints the
 *			env passed as argument
 *
 * Returns: Nothing
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
