#include "main.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

void close_file(int fd);
char *create_buffer(void);
void copy_file(const char *from, const char *to, char *buffer);

/**
* close_file - Closes file descriptor.
* @fd: The file descriptor to be closed.
*/
void close_file(int fd)
{
if (close(fd) == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
}

/**
* create_buffer - Allocates buffer.
*
* Return: A pointer to the newly-allocated buffer.
*/
char *create_buffer(void)
{
char *buffer;

buffer = malloc(sizeof(char) * BUFSIZE);
if (buffer == NULL)
{
dprintf(STDERR_FILENO, "Error: Can't malloc\n");
exit(98);
}

return (buffer);
}

/**
* copy_file - Copies the contents of a file to another file.
* @from: The name of the source file.
* @to: The name of the destination file.
* @buffer: The buffer to use for copying.
*/
void copy_file(const char *from, const char *to, char *buffer)
{
int fd_from, fd_to, bytes_read, bytes_written;

fd_from = open(from, O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
free(buffer);
exit(98);
}

fd_to = open(to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
free(buffer);
close_file(fd_from);
exit(99);
}

do {
bytes_read = read(fd_from, buffer, BUFSIZE);
if (bytes_read == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", from);
free(buffer);
close_file(fd_from);
close_file(fd_to);
exit(98);
}

bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
free(buffer);
close_file(fd_from);
close_file(fd_to);
exit(99);
}
} while (bytes_read > 0);

free(buffer);
close_file(fd_from);
close_file(fd_to);
}

/**
* main - Entry point.
* @argc: The number of arguments.
* @argv: The arguments.
*
* Return: Always 0.
*/
int main(int argc, char **argv)
{
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer();
copy_file(argv[1], argv[2], buffer);

return (0);
}

