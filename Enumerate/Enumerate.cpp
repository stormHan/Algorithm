#include <iostream>
#include <stdio.h>
#include <vector>


//--------�ҵ�С��N���������--------------------
//������ö�ٵķ�����Ҫ��ȥ�ж�n-1, n-2...�Ƿ�������Ҫ�졣
int findNum(const int N)
{
	int ret;

	std::vector<int> prim;
	prim.push_back(2);
	bool flag = true; //��ʶ��ǰ�����Ƿ�������
	for (int i = 3; i < N; i = i + 2/* �ų�ż��*/)
	{
		for (int j = 0; j < prim.size() - 1; ++j)
		{
			if (i % prim[j] == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) prim.push_back(i);//�����ǰi������������Push������������

		flag = true;
	}

	return prim[prim.size() - 1];
}


//-------------------------------------------------
//**Ϩ������**
//ö�ٵ�һ�е�������� 2^6 = 64�֡�
//����ÿһ������������1-4�н��Ψһ������жϵ������Ƿ����ö���Ϩ�����ǣ���õ���ȷ�⡣

int press[6][8], puzzle[6][8];

bool guess()
{
	for (int i = 1; i < 7; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			//����Press��һ�к�puzzle���飬����press�����е�ֵ
			press[i + 1][j] = (puzzle[i][j] + press[i - 1][j] + press[i][j] + press[i][j + 1] + press[i][j - 1]) % 2;
		}
	}
	for (int i = 1; i < 7; ++i)
	{
		//�ж��������press�����ܷ�Ϩ������е����е�
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
		//��press��һ�е�Ԫ�صĸ���ȡֵ����ö�٣����ο���
		c = 1;
		press[1][c]++;
		//�ۼӽ�λ
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

	//������ľ���ı�Ե��0���
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