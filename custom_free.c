#include "shell_header.h"

/**
 * custom_free - frees allocated memory
 * @ptr_to_be_freed: generic void pointer should be freed
 * Return: Success
*/
void custom_free(void *ptr_to_be_freed)
{
	if (ptr_to_be_freed != NULL)
	{
		free(ptr_to_be_freed);
		ptr_to_be_freed = NULL;
	}
}
