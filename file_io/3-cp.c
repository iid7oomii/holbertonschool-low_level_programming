#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * check_args - Checks if arguments are correct
 * @argc: Number of arguments
 */
void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_source - Opens source file
 * @filename: Source filename
 *
 * Return: File descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - Opens destination file
 * @filename: Destination filename
 * @fd_from: Source file descriptor
 *
 * Return: File descriptor
 */
int open_dest(char *filename, int fd_from)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		close(fd_from);
		exit(99);
	}
	return (fd);
}

/**
 * copy_files - Copies content from source to destination
 * @fd_from: Source file descriptor
 * @fd_to: Destination file descriptor
 * @file_from: Source filename
 * @file_to: Destination filename
 */
void copy_files(int fd_from, int fd_to, char *file_from, char *file_to)
{
	int bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * close_files - Closes file descriptors
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
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	check_args(argc);
	fd_from = open_source(argv[1]);
	fd_to = open_dest(argv[2], fd_from);
	copy_files(fd_from, fd_to, argv[1], argv[2]);
	close_files(fd_from, fd_to);
	return (0);
}
