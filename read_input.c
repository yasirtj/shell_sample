#include "shell_header.h"

/**
 * read_user_input - reads user input
 * @user_input: command
 * @user_input_size: command size
 * Return: Success
*/
void read_user_input(char *user_input, size_t user_input_size);
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
	string_copy = malloc(sizeof(char) * (read_char_num + 1));
	if (string_copy == NULL || user_input == NULL)
	{
		custom_free(string_copy);
		custom_free(user_input);
		custom_exit(1, "Failed to allocate memory!\n");
	}
	else
	{
		strcpy(string_copy, user_input);
	}
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
		/* free(new_tokens); */
		custom_exit(1, "Failed to allocate memory for your tokens");
	}
	generated_token = strtok(string_copy, delimeter);
	while (generated_token != NULL)
	{
		new_tokens[i] = malloc(sizeof(char) * (strlen(generated_token) + 1));
		if (new_tokens[i] != NULL && generated_token != NULL)
		{
			strcpy(new_tokens[i], generated_token);
		}
		new_tokens[i][strlen(generated_token)] = '\0';
		generated_token = strtok(NULL, delimeter);
		i++;
	}
	new_tokens[i] = NULL;
	/* free(string_copy); */
	execute_command(new_tokens);
	for (i = 0; new_tokens[i] != NULL; i++)
	{
		free(new_tokens[i]);
	}
	free(new_tokens);
	free(string_copy);
	free(user_input);
}
