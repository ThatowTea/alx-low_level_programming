#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: 1 for expected results else -1.
 **/

int append_text_to_file(const char *filename, char *text_content)
{
	int tcon = 0;
	int top = 0, tap = 0;

	if (filename == NULL)
		return (-1);
	top = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (top == -1)
		return (-1);
	if (text_content != NULL)
	{
		for (tcon = 0; text_content[tcon] != '\0'; tcon++)
			;
		tap = write(top, text_content, tcon);
		if (tap == -1)
			return (-1);
	}
	close(top);
	return (1);
}
