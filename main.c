#include "main.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: array of null terminated string
 * Return: Success
*/

int main(int argc __attribute__((unused)), char **argv)
{
	char *user_input = NULL;
/* 	char *delimeter = " "; */
	/* char **cmd = NULL;*/
size_t i, cmd_size = 0;

argv = malloc(sizeof(char *) * (cmd_size + 1));
for (;;)
	{
		view_prompt();
		read_user_input(user_input, cmd_size);
		/* getline(&user_input, &cmd_size, stdin);
		execute_command(argv);*/
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
	free(argv);
	}
	return (0);
}
