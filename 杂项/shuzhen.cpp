#include<stdio.h>
#define N 10

void fun(int n, int a[][N])
{
	int i = 0, j = 0, x = 1;

	while(x <= n*n)
	{
		while(j < n && a[i][j] == 0)
		{
			a[i][j] = x;
			x++;
			j++;
		}
		i++;
		j--;

		while(i < n && a[i][j] == 0)
		{
			a[i][j] = x;
			x++;
			i++;
		}
		j--;
		i--;

		while(j >= 0 && a[i][j] == 0)
		{
			a[i][j] = x;
			x++;
			j--;
		}
		i--;
		j++;

		while(i >= 0 && a[i][j] == 0)
		{
			a[i][j] = x;
			x++;
			i--;
		}
		j++;
		i++;
	}
}


int main()
{
    int a[N][N] = {0};
	fun(N, a);
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%3d", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}