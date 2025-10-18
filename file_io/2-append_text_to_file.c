#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file
 * @text_content: The NULL terminated string to add
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	while (text_content[length] != '\0')
		length++;

	bytes_written = write(fd, text_content, length);
	if (bytes_written == -1 || bytes_written != length)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
