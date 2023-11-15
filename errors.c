#include "shell.h"

int _putsfd(char *str, int fd);
/**
 *e_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void e_puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * charEput - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int charEput(char c)
{
	static int i;
	static char buf[BUFF_SIZE_WRITE];

	if (c == FLUSH_BUFF || i >= BUFF_SIZE_WRITE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != FLUSH_BUFF)
		buf[i++] = c;
	return (1);
}

/**
 * fd_put - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fd_put(char c, int fd)
{
	static int i;
	static char buf[BUFF_SIZE_WRITE];

	if (c == FLUSH_BUFF || i >= BUFF_SIZE_WRITE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != FLUSH_BUFF)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
