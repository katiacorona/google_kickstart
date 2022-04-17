#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_possible(char *I, char *P)
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

int main(void)
{
	char *I,*P, *aux = "IMPOSSIBLE";
	int case_n, result;

	case_n = 1;
	I = "Ilovecoding";
	P = "IIllovecoding";
	printf("Case %i: I = %s P = %s\n", case_n, I, P);
	result = is_possible(I, P);
	if (result == -1)
	{
		printf("Case #%i: %s\n", case_n, aux);
		return (1);
	}
	printf("Case #%i: %i\n", case_n, result);
	return (0);
}
