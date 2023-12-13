#include "shell_header.h"

/**
 * cmd_locater - locates the command
 * @string_cmd: the command we want to locate
 * Return: null terminated array of characters
 * represents the location of the command
*/
char *cmd_locater(char *string_cmd);
char *cmd_locater(char *string_cmd)
{
	char *cmd_path, *cmd_path_copy, *token, *fp, *execve_path;
	int cmd_length, dir_len;
	struct stat bfr;

	cmd_path = getenv("PATH");
	if (cmd_path)
	{
		cmd_path_copy = strdup(cmd_path);
		cmd_length = strlen(string_cmd);
		token = strtok(cmd_path_copy, ":");
		while (token != NULL)
		{
			dir_len = strlen(token);
			fp = malloc(cmd_length + dir_len + 2);
			/* _strcat(fp, "\0"); */
			if (fp == NULL)
			{
				perror("ERROR\n");
				free(fp);
				fp = NULL;
				custom_free(cmd_path_copy);
				exit(EXIT_FAILURE);
			}
			if (token != NULL && string_cmd != NULL)
			{
				strcpy(fp, token);
				_strcat(fp, "/");
				_strcat(fp, string_cmd);
				fp[cmd_length + dir_len + 1] = '\0';

				/* strcat(fp, "\0"); */
			}
			if (stat(fp, &bfr) == 0)
			{
				execve_path = strdup(fp);
				free(fp);
				fp = NULL;
				/* return (fp); */
				custom_free(cmd_path_copy);
				return (execve_path);
			}
			else
			{
				execve_path = NULL;
				custom_free(execve_path);
				custom_free(fp);
				token = strtok(NULL, ":");
			}
		}
		free(fp);
		if (stat(string_cmd, &bfr) == 0)
		{
			/* custom_free(cmd_path_copy); */
			return (string_cmd);
			/*free(cmd_path_copy);*/
			/*cmd_path_copy = NULL; */
		}
		/* custom_free(cmd_path_copy); */
		free(fp);
		fp = NULL;
		return (NULL);
	}
	return (NULL);
}
