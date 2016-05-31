#include <stdio.h>

int cases;
int n;
char** color;
int** isPainted;
int max = -1;

bool painting()
{
	for (int i = 2; i < n + 1; ++i)
	{
		for (int j = 1; j < n + 1; ++j)
		{
			isPainted[i][j] = (isPainted[i - 1][j] + isPainted[i - 1][j - 1]
				+ isPainted[i - 1][j + 1] + isPainted[i - 2][j]) % 2;
			if (color[i - 1][j] == 'W') isPainted[i][j] = 1 - isPainted[i][j];
		}
	}

	for (int i = i; i < n + 1; ++i)
	{
		if (color[n][i] == 'W' && (isPainted[n][i - 1] + isPainted[n][i] + isPainted[n][i + 1]) % 2 == 0)
		{
			return false;
		}
		if (color[n][i] == 'Y' && (isPainted[n][i - 1] + isPainted[n][i] + isPainted[n][i + 1]) % 2 == 1)
		{
			return false;
		}
	}
	return true;
}

int count()
{
	int c = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; i <= n; ++j)
		{
			if (isPainted[i][j] == 1)
				c++;
		}
	}
	return c;
}

void enumerate()
{
	int tmp;

	for (int i = 1; i < n + 1; ++i)
	{
		isPainted[1][i] = 0;
	}
	
	int c;
	while (1)
	{
		bool f = painting();

		if (f)
		{
			int temp = count();
			if (temp > max) max = temp;
		}
		

		c = 1;
		while (isPainted[1][c] != 0)
		{
			isPainted[1][c] = 0;
			c++;
		}
		isPainted[1][c] += 1;
		if (c == n + 1) break;
	}
}

void input()
{
	scanf("%d", &cases);

	while (cases++ > 0)
	{
		scanf("%d", &n);
		color = new char*[n + 1];
		isPainted = new int*[n + 1];

		for (int i = 0; i < n + 1; ++i)
		{
			color[i] = new char[n + 2];
			isPainted[i] = new int[n + 2];
		}

		for (int i = 0; i < n + 1; ++i)
		{
			color[i][0] = 'Y';
			isPainted[i][0] = 0;
			color[i][n + 1] = 'Y';
			isPainted[i][n + 1] = 0;
		}
		for (int i = 1; i < n + 1; ++i)
		{
			isPainted[0][i] = 0;
			color[0][i] = 'Y';
		}

		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; i < n + 1; ++j)
			{
				scanf("%d", &color[i][j]);
			}
		}

		enumerate();

		printf("%d ", max);
	}
}