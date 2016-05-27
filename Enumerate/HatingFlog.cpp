#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

//-------------------------------------------------
//**���������**
//������һ���ṹ������������̤ˮ���ĺ�������
struct Plant
{
	int x;
	int y;
};

Plant plants[5000];
int r, c, n;
//����һ����̬�Ŀռ�����ŵ����Ƿ񱻲�̤
int **field;

int searchPath(int dx, int dy, Plant p)
{
	int step = 1;
	int x = p.x;
	int y = p.y;

	while (x >= 1 && x <= c && y >= 1 && y <= r)
	{
		step++;
		//��һ��Ҳ�����ö����������plants������û��x, y���Ӧ�ĵ� 
		if (field[x][y] != 1 /* std::!binary_search(plants, plants + n, plants)*/) return 0;

		x += dx;
		y += dy;
	}
	return step;
}

void input()
{
	scanf("%d %d %d", &r, &c, &n);

	field = new int*[r + 1];
	for (int i = 0; i < r + 1; ++i)
	{
		field[i] = new int[c + 1];
	}
	//�ȳ�ʼ����Ϊ0
	for (int i = 1; i < r + 1; ++i)
	{
		for (int j = 1; j < c + 1; ++j)
		{
			field[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &plants[i].x, &plants[i].y);
		field[plants[i].x][plants[i].y] = 1;
	}

	for (int i = 1; i < r + 1; ++i)
	{
		for (int j = 1; j < c + 1; ++j)
		{
			printf("%d ", field[i][j]);
		}
		printf("\n");
	}

}

int hatingFlog()
{
	int dx, dy;
	int max = 2;
	int tmpStep;
	input();

	std::sort(plants, plants + n);

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			dx = plants[j].x - plants[i].x;
			dy = plants[j].y - plants[i].y;
			//�����һ�����ǰһ���㻹��field�ڣ���϶��������Ŵ𰸵���㣬���ڶ����㡣
			if (plants[i].x - dx >= 1 && plants[i].x - dx <= c && plants[i].y - dy >= 1 && plants[i].y <= r)
				continue;
			//�����һ���㾭����max��С��step��Խ���ˣ��϶�Ҳ����������������
			//�����ǰ�x�ź���ģ������󻻵ڶ������ȻҲ���������������Ի���һ���㡣
			if (plants[i].x + dx * (max - 1) > r)
				break;

			//���y�������Խ��
			if (plants[i].y + dy * (max - 1) > c || plants[i].y + dy * (max - 1) < 1)
				continue;

			//���������ǰ���ų��޷��ų��õ꣬��ô������·����step�������Ƿ�Ϊ���
			int tmpStep = searchPath(dx, dy, plants[i]);
			if (tmpStep > max) max = tmpStep;

		}
	}
	if (max <= 2) max = 0;
	return max;
}

bool operator < (const Plant& p1, const Plant& p2)
{
	if (p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}