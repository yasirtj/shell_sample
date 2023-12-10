#include "shell_header.h"

/**
 * io_print - prints to the IO stream
 * @io_msg: message to be printed to the IO stream
 * Return: Success
*/

void io_print(const char *io_msg)
{
	write(1, io_msg, strlen(io_msg));
}
