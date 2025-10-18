#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * open_files - Opens source and destination files
 * @argv: Array of arguments
 * @fd_from: Pointer to source file descriptor
 * @fd_to: Pointer to destination file descriptor
 */
void open_files(char *argv[], int *fd_from, int *fd_to)
{
	*fd_from = open(argv[1], O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	*fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(*fd_from);
		exit(99);
	}
}

/**
 * copy_content - Copies content from source to destination
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @argv: Array of arguments
 */
void copy_content(int fd_from, int fd_to, char *argv[])
{
	int bytes_read, bytes_written;
	char buffer[1024];

	bytes_read = read(fd_from, buffer, 1024);
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98);
	}

	while (bytes_read > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
		bytes_read = read(fd_from, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close(fd_from);
			close(fd_to);
			exit(98);
		}
	}
}

/**
 * close_files - Closes file descriptors with error checking
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 */
void close_files(int fd_from, int fd_to)
{
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - Copies the content of a file to another file
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, or exit with error code
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv, &fd_from, &fd_to);
	copy_content(fd_from, fd_to, argv);
	close_files(fd_from, fd_to);

	return (0);
}
