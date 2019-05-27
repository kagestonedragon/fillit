#include <stdio.h>
#include <stdlib.h>

void		sort(int *a, int n)
{
	int		i;
	int		j;
	int		temporary;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[j] < a[i])
			{
				temporary = a[j];
				a[j] = a[i];
				a[i] = temporary;
			}
			j++;
		}
		i++;
	}
}

void		print(int *a, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		printf("%d, ", a[i]);
		i++;
	}
	printf("\n");
}

int			main(void)
{
	int		*a;
	int		n;
	int		i;

	n = 10;
	a = (int *)malloc(sizeof(int) * n);
	a[0] = 5;
	a[1] = 2;
	a[2] = -3;
	a[3] = 20;
	a[4] = 55;
	a[5] = 4;
	a[6] = -44444;
	a[7] = 22;
	a[8] = 33;
	a[9] = 33;
	print(a, n);
	sort(a, n);
	print(a, n);
	return (0);
}
