#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads text file and prints to STDOUT
 * @filename: Name of the file to read
 * @letters: Number of letters to read from the file
 * Return: Number of bytes read and printed on success, 0 otherwise
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd, w = 0, t;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	t = read(fd, buf, letters);
	if (t == -1)
		goto cleanup;

	w = write(STDOUT_FILENO, buf, t);
	if (w == -1)
		goto cleanup;

cleanup:
	free(buf);
	close(fd);
	return (w);
}

