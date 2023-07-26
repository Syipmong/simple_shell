#include "shell1.h"

/**
 * _strcat - a function that concatenates two strings
 * @dest: destination for string
 * @src: source of string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest; /* set pointer to end of destination */

	while (*ptr)
		ptr++;
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strlen - a function that returns the length of a string
 * @s: parameter for argument
 * Return: Always 0.
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}


/**
 * _strcpy - a function that copies a string
 * @dest: parameter for argument
 * @src: parameter for argument
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
		dest[a] = src[a];
	dest[a] = '\0';
	return (dest);
}

/**
 * freewords- a function that free words
 * @commands: commands to free
 *
 * Return: Nothing
 */
void freewords(char **commands)
{
	int i;

	for (i = 0; commands[i] != NULL; i++)
	{
		free(commands[i]);
	}
	free(commands);
}


/**
 * _strcmp - a function to compare two strings
 * @s1: first string
 * @s2: second string
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
