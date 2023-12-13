#include "shell_header.h"

/**
 * view_prompt - prompts user to enter output
 * Return: Success
*/

void view_prompt(void)
{
	const char *view_shell;

	view_shell = "shell";
	io_print(view_shell);
}
