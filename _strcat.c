#include "shell_header.h"

/**
 * _strcat - concatenates two strings
 * @src: source appended string
 * @dest: resulting string destination
 * Return: pointer to resulting string dest
 **/

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = strlen(dest);

	while (dest[i] != '\0')
	{
		++i;
	}
	for (j = 0; (src[j] != '\0'); ++j, ++i)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
