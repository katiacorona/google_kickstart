/**
 * 04/17/2022
 * Note: Managed to work with the example input provided inside the main func-
 * tion, and now we need to obtain the contents from a file. The first line
 * from this file contains the number of lines to be read. Need to take line 0
 * and atoi it to get the number of lines to be read.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int is_possible(char *s1, char *s2)
{
	int i = strlen(I), p = strlen(P), n = 0;

	printf("I len = %i P len = %i\n", i, p);
	if (P == NULL || I == NULL)
	{
		perror("Error:\n");
		exit(1); /* Error */
	}
	if (i > p)
		return (-1); /* IMPOSSIBLE */
	while (i >= 0)
	{
		while (p >= 0)
		{
			if ((P[p] != I[i]) && (p == i))
			{
				printf("Deleted --> %c\n", P[p]);
				return (-1); /* IMPOSSIBLE */
			}
			else if (P[p] != I[i])
			{
				printf("Deleted --> %c\n", P[p]);
				n++;
			}
			else
				i--;
			p--;
		}
	}
	return (n); /* True: POSSIBLE with n numbers of deletes */
}

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(1);
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	char *lines[], *buffer;
	int case_n, lines_n, result;

	FILE * fin = fopen(argv[1], "r");

	buffer = create_buffer(argv[1]);

	if (argc != 2)
	{
		dprintf(2, "Usage: %s filename\n", av[0]);
		exit(1);
	}

	printf("Case %i: I = %s P = %s\n", case_n, I, P);
	result = is_possible(I, P);
	if (result == -1)
	{
		printf("Case #%i: IMPOSSIBLE\n", case_n);
		return (1);
	}
	printf("Case #%i: %i\n", case_n, result);
	return (0);
}
