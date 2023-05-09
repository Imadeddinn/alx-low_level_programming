#include <stdlib.h>
#include "main.h"

/**
* append_text_to_file - Appends a string to the end of a specified file.
* @filename: A pointer to the name of the file.
* @text_content: A pointer to the string to append to the end of the file.
* Return: On success 1, On failure -1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (len > 0)
		write(fd, text_content, len);

	close(fd);
	return (1);
}

