#include <iostream>
#include <stdio.h>
#include <vector>


//--------找到小于N的最大素数--------------------
//用这种枚举的方法，要比去判断n-1, n-2...是否是质数要快。
int findNum(const int N)
{
	int ret;

	std::vector<int> prim;
	prim.push_back(2);
	bool flag = true; //标识当前的数是否是质数
	for (int i = 3; i < N; i = i + 2/* 排除偶数*/)
	{
		for (int j = 0; j < prim.size() - 1; ++j)
		{
			if (i % prim[j] == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) prim.push_back(i);//如果当前i是质数，把它Push到质数数组里

		flag = true;
	}

	return prim[prim.size() - 1];
}


//-------------------------------------------------
//**熄灯问题**
//枚举第一行的所有情况 2^6 = 64种。
//对于每一种情况，下面的1-4行结果唯一，最后判断第五行是否正好都别熄灭，若是，则得到正确解。

int press[6][8], puzzle[6][8];

bool guess()
{
	for (int i = 1; i < 7; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			//根据Press第一行和puzzle数组，计算press其它行的值
			press[i + 1][j] = (puzzle[i][j] + press[i - 1][j] + press[i][j] + press[i][j + 1] + press[i][j - 1]) % 2;
		}
	}
	for (int i = 1; i < 7; ++i)
	{
		//判断所计算的press数组能否熄灭第五行的所有灯
		if ((puzzle[5][i] + press[5][i] + press[5][i - 1] + press[5][i + 1]) % 2 == 1)
			return false;
	}
	return true;
}

void enumerate()
{


	int c;
	for (c = 1; c < 7; ++c)
	{
		press[1][c] = 0;
	}
	while (!guess())
	{
		//对press第一行的元素的各种取值进行枚举，依次考虑
		c = 1;
		press[1][c]++;
		//累加进位
		while (press[1][c] > 1)
		{
			press[1][c] = 0;
			c++;
			press[1][c] += 1;
		}
	}
	
	return;
}


int main(int argc, char** argv)
{

	int cases, i, r, c;
	scanf("%d", &cases); 

	//将扩大的矩阵的边缘用0填充
	for (r = 0; r < 6; r++)
	{
		press[r][0] = 0;
		press[r][7] = 0;
	}
	for (c = 0; c < 8; c++)
	{
		press[0][c] = 0;
	}

	for (i = 0; i < cases; ++i)
	{
		for (r = 1; r < 6; ++r)
		{
			for (c = 1; c < 7; ++c)
			{
				scanf("%d", &puzzle[r][c]);
			}
		}
		enumerate();
		
		printf("PUZZLE# %d\n", i + 1);
		for (r = 1; r < 6; ++r)
		{
			for (c = 1; c < 7; ++c)
			{
				printf("%d ", press[r][c]);
			}
			printf("\n");
		}
	}

	
	return 0;
}