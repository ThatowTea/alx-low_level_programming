#include "main.h"

/**
 * main - Copies the content of a file to another file.
 * @argc: count.
 * @argv: vector.
 * Return: 0
 **/

int main(int argc, char *argv[])
{
	ssize_t rd, fop, sop, fend, send;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fop = open(argv[1], O_RDONLY);
	if (fop == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	sop = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while ((rd = read(fop, buf, BUFSIZ)) > 0)
	{
		if (sop == -1 || write(sop, buf, rd) != rd)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fop);
		close(sop);
		exit(99);
	}
	}
	if (rd == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	exit(98);
	}
	fend = close(fop), send = close(sop);
	if (fend == -1 || send == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %ld\n", fend == -1 ? fop : sop);
	exit(100);
	}
	return (0);
}
