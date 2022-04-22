/**
 * 04/21/2022
 * Note:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int is_possible(char *s1, char *s2)
{
	int i = strlen(s1), p = strlen(s2), n = 0;

	printf("I len = %i P len = %i\n", i, p);
	if (s2 == NULL || s1 == NULL)
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
			if ((s2[p] != s1[i]) && (p == i))
			{
				printf("Deleted --> %c\n", s2[p]);
				return (-1); /* IMPOSSIBLE */
			}
			else if (s2[p] != s1[i])
			{
				printf("Deleted --> %c\n", s2[p]);
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
		printf("Error: Can't write to %s\n", file);
		exit(1);
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	char *line_buffer = NULL, *s[2], *cases;
	int line_count = 0, c, case_num = 0, result;
	size_t line_bufsize = 0;
	ssize_t line_size;
	FILE *fp;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	fp = fopen(argv[1], "r");

	line_size = getline(&line_buffer, &line_bufsize, fp);
	cases = malloc((line_size + 1) * sizeof(char));
	strcpy(cases, line_buffer);
	cases = strtok(cases, "\n");
	c = atoi(cases);
	printf("Number of cases in the file: %i\n", c);
	while (line_size > 0)
	{
		line_size = getline(&line_buffer, &line_bufsize, fp);
		s[line_count] = malloc((line_size + 1) * sizeof(char));
		strcpy(s[line_count], line_buffer);
		line_count++;
		case_num++;
		/* printf("%s\n", line_buffer); */
	}
	s[0] = strtok(s[0], "\n");
	s[1] = strtok(s[1], "\n");
	result = is_possible(s[0], s[1]);
        if (result == -1) /* If P cannot match I, even with deletions */
        {
                printf("Case #%i: IMPOSSIBLE\n", case_num);
                return (1);
        }
        printf("Case #%i: %i\n", case_num, result);
        /* P can match I, or is equal to I (returned 0 or a positive int) */

	printf("%s\n%s\n", s[0], s[1]);

	free(line_buffer);
	free(s[0]);
	free(s[1]);
	fclose(fp);
	return (0);
}
