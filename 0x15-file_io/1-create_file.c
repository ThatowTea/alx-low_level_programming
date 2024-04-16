#include "main.h"

/**
 * create_file - Function that creates a file.
 * @filename: Name for file.
 * @text_content: Text to put into file.
 * Return: 1 for expected results else -1.
 **/

int create_file(const char *filename, char *text_content)
{
	int cf, fcon, wryt;

	if (filename == NULL)
		return (-1);
	cf = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (cf == -1)
		return (-1);

	if (text_content)
	{
		fcon = 0;
		while (text_content[fcon])
			fcon++;
		wryt = write(cf, text_content, fcon);
		if (wryt != fcon)
			return (-1);
	}

	close(cf);
	return (1);
}
