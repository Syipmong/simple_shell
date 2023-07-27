#include "main1.h"
#include "shell1.h"

/**
 * split_commands - a function that tokenizes commands
 * @str: string or commands to split
 * @delim: delimeter to split with
 *
 * Return: an array of tokenize commands
 */

char **split_commands(char *str, char *delim)
{
	int strCount = 0;
	int index;
	char *sp;
	int i, j;
	char **words = NULL;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			strCount++;
		}
	}
	strCount++;

	words = malloc(sizeof(char *) * (strCount + 1));
	if (words == NULL)
	{
		perror("Could not allocate memory\n");
		return (NULL);
	}
	sp = strtok(str, delim);
	for (index = 0; sp != NULL; index++)
	{
		words[index] = malloc(sizeof(char) * _strlen(sp) + 1);
		if (words[index] == NULL)
		{
			printf("Memory allocation failed.\n");
			/* free previously allocated memory*/
			for (j = 0; j < index; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}
		_strcpy(words[index], sp);
		sp = strtok(NULL, delim);
	}
	words[index] = NULL;
	return (words);
}
