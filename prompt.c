#include "main1.h"

/**
 * prompt -  a function that prints a message to stdout
 * @prompt: string to print
 * Description: This meassage is printed when in interactive mode
 *
 * Return: Nothing
 */
void prompt(char *prompt)
{
	int prompt_len = strlen(prompt);

	write(STDOUT_FILENO, prompt, prompt_len);
}
