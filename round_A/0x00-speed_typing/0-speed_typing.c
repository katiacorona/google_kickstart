#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_possible(char *I, char *P)
{
	int i = strlen(I), p = strlen(P), n = 0;
	/* n is a counter for the number of deletions to be made on P so that
	 * it matches I string.
	 */
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

int main(void)
{
	char *I,*P, *aux = "IMPOSSIBLE";
	int case_n, result;

	case_n = 1;
	I = "Ilovecoding";
	P = "IIllovecoding";
	printf("Case %i: I = %s P = %s\n", case_n, I, P);
	result = is_possible(I, P);
	if (result == -1) /* If P cannot match I, even with deletions */
	{
		printf("Case #%i: %s\n", case_n, aux);
		return (1);
	}
	printf("Case #%i: %i\n", case_n, result);
	/* P can match I, or is equal to I (returned 0 or a positive int) */
	return (0);
}
