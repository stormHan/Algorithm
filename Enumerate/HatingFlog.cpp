#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

//-------------------------------------------------
//**讨厌的青蛙**
//定义了一个结构体用于描述踩踏水稻的横纵坐标
struct Plant
{
	int x;
	int y;
};

Plant plants[5000];
int r, c, n;
//申请一个动态的空间来存放稻田是否被踩踏
int **field;

int searchPath(int dx, int dy, Plant p)
{
	int step = 1;
	int x = p.x;
	int y = p.y;

	while (x >= 1 && x <= c && y >= 1 && y <= r)
	{
		step++;
		//这一步也可以用二叉查找来找plants里面有没有x, y相对应的点 
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
	//先初始化其为0
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
			//如果第一个点的前一个点还在field内，则肯定不是最优答案的起点，换第二个点。
			if (plants[i].x - dx >= 1 && plants[i].x - dx <= c && plants[i].y - dy >= 1 && plants[i].y <= r)
				continue;
			//如果第一个点经过比max还小的step就越界了，肯定也不可能满足条件。
			//由于是按x排好序的，再往后换第二个点必然也不满足条件，所以换第一个点。
			if (plants[i].x + dx * (max - 1) > r)
				break;

			//如果y方向过早越界
			if (plants[i].y + dy * (max - 1) > c || plants[i].y + dy * (max - 1) < 1)
				continue;

			//如果三种提前的排除无法排除该店，那么算这条路径的step，看其是否为最大。
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