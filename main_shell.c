#include "shell_header.h"

/**
 * main - main function
 * Return: Success
*/

int main(void)
{
	char *user_input = NULL;
/* 	char *delimeter = " "; */
	/* char **cmd = NULL;*/
size_t i, cmd_size = 0;

char **argv = malloc(sizeof(char *) * (cmd_size + 1));
for (;;)
	{
		view_prompt();
		read_user_input(user_input, cmd_size);
		/* getline(&user_input, &cmd_size, stdin); */
		/* execute_command(argv); */
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
	free(argv);
	}
	return (0);
}
