#include "main.h"

/**
 * read_textfile - function that reads a text file and prints.
 * @filename: Name of the file.
 * @letters: Number of characters to read.
 * Return: Actual number of letters read, 0 if end of file.
 **/

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t go, rd, rtp;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	go = open(filename, O_RDONLY);
	rd = read(go, buf, letters);
	rtp = write(STDOUT_FILENO, buf, rd);

	if (go == -1 || rd == -1 || rtp == -1 || rtp != rd)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(go);

	return (rtp);
}
