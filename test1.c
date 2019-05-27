#include <stdio.h>
#include <stdlib.h>

void		swap(int *a, int i, int j)
{
	int		temporary;

	temporary = a[i];
	a[i] = a[j];
	a[j] = temporary;
}

int			next_combination(int *a, int n)
{
	int		i;
	int		j;
	while (i != -1 && a[i] >= a[i + 1])
		i--;
	if (i == -1)
		return (0);
	j = amount - 1;
	while (a[i] >= a[j])
		j--;
	swap(input, i, j);
	j = i + 1;
	i = amount - 1;
	while (j < i)
		swap(input, j++, i--);
	return (1);
}

void		Print(int *a, n)
{
	int		i;

	i = -1;
	while (++i < n)
		printf("%d ", a[i]);
	printf("\n");
}
