#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *filename);
void close_file(int file_descriptor);

/**
* create_buffer - Allocates memory for a buffer of size 1024 bytes.
* @file: The name of the file for which the buffer is created.
* Return: A pointer to the newly-allocated buffer.
*/

char *create_buffer(char *filename)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", filename);
exit(99);
}

return (buffer);
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to be closed.
*/

void close_file(int file_descriptor)
{
int close_status;

close_status = close(file_descriptor);

if (close_status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
exit(100);
}
}

/**
* main - Copies the contents of one file to another.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
* Return: 0 on success.
* Description: If the number of arguments is incorrect, exit with code 97.
* If the source file cannot be opened or read, exit with code 98.
* If the destination file cannot be created or written to, exit with code 99.
* If either the source or destination file can't be closed, exit with code 100.
*/

int main(int argc, char *argv[])
{
int file_from, file_to, read_status, write_status;
char *buffer;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
file_from = open(argv[1], O_RDONLY);
read_status = read(file_from, buffer, 1024);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (file_from == -1 || read_status == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

write_status = write(file_to, buffer, read_status);
if (file_to == -1 || write_status == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

read_status = read(file_from, buffer, 1024);
file_to = open(argv[2], O_WRONLY | O_APPEND);

} while (read_status > 0);

free(buffer);
close_file(file_from);
close_file(file_to);

return (0);
}

