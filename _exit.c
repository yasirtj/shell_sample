#include "shell_header.h"

/**
 * custom_exit - custom version of exit function
 * @status_code: status code
 * @err_msg: error message
*/

void custom_exit(int status_code, const char *err_msg)
{
	if (err_msg != NULL)
	{
		io_print(err_msg);
	}
	exit(status_code);
}
