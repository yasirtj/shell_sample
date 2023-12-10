#include "shell_header.h"

/**
 * read_user_input - reads user input
 * @cmd: command
 * @cmd_size: command size
 * Return: Success
*/

void read_user_input(char *user_input, size_t user_input_size)
{
	char *string_copy = NULL, *generated_token, *delimeter = " \n";
	char **new_tokens;
	ssize_t read_char_num;
	size_t number_of_tokens = 0, i = 0;

	read_char_num = getline(&user_input, &user_input_size, stdin);
	if (read_char_num == -1)
	{
		custom_exit(1, "Shell Exited!\n");
	}
	string_copy = malloc(sizeof(char) * read_char_num);
	if (string_copy == NULL)
	{
		free(string_copy);
		custom_exit(1, "Failed to allocate memory!\n");
	}
	strcpy(string_copy, user_input);
	generated_token = strtok(user_input, delimeter);
	while (generated_token != NULL)
	{
		number_of_tokens++;
		generated_token = strtok(NULL, delimeter);
	}
	number_of_tokens++;
	new_tokens = malloc(sizeof(char *) * (number_of_tokens + 1));
	if (new_tokens == NULL)
	{
		free(new_tokens);
		custom_exit(1, "Failed to allocate memory for your tokens");
	}
	generated_token = strtok(string_copy, delimeter);
	while (generated_token != NULL)
	{
	new_tokens[i] = malloc(sizeof(char) * (strlen(generated_token)));
		strcpy(new_tokens[i], generated_token);
		generated_token = strtok(NULL, delimeter);	
		i++;
	}
	new_tokens[i] = NULL;
	execute_command(new_tokens);
	free(string_copy);
	free(user_input);
}
