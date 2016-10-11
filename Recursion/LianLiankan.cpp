#include <stdio.h>
#include <memory>

#define MAX 75

int w, h, minstep;
char board[MAX+ 2][MAX + 2];
//��һ��2ά������������ֵ��ѧ
int to[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } }; // 0-3�ֱ������������
bool mark[MAX + 2][MAX + 2];//�������

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f)
{
	if (step > minstep) return; //�������Ž⣬ֱ�ӷ���
	//�����յ�
	if (now_x == end_x && now_y == end_y)
	{
		//������С·��
		if (step < minstep) minstep = step;
		return;
	}
	
	//����δ�����յ㣬���õݹ������һ��
	//���������������߷�
	for (int i = 0; i < 4; ++i)
	{
		int x = now_x + to[i][0];
		int y = now_y + to[i][1];

		if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2) && ((board[y][x] == ' ' && mark[y][x] == false) || (x == end_x && y == end_y)))
		{
			mark[y][x] = true;

			if (f == i) Search(x, y, end_x, end_y, step, i);
			else
				Search(x, y, end_x, end_y, step + 1, i);

			mark[y][x] = false;
		}
	}
}


int main()
{
	int Boardnum = 0;
	while (scanf("%d %d", &w, &h))
	{
		if (w == 0 && h == 0) break;
		Boardnum++;

		printf("Board #%d\n", Boardnum);

		int i, j;
		for (i = 0; i < MAX; ++i){
			board[0][i] = ' ';
			board[h + 1][i] = ' ';
			board[i][0] = ' ';
			board[i][w + 1] = ' ';
		}
			
		/*ע�����ֶ��뷽ʽ����cmd��
			XXXXX X
			XXX  XX
			X XXXXX
			XXXXXXX
		  ��ʽ����һ����ά�ַ�����
		*/
		for (i = 1; i <= h; ++i)
		{
			getchar();
			for (j = 1; j <= w; ++j)
			{
				board[i][j] = getchar();
			}
		}

		int begin_x, begin_y, end_x, end_y, count = 0;
		while (scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y) && begin_x > 0)
		{
			count++;
			minstep = 10000;
			memset(mark, false, sizeof(mark));

			//�ݹ�����
			Search(begin_x, begin_y, end_x, end_y, 0, -1);

			if (minstep < 10000) printf("Pair %d : %d Segments.\n", count, minstep);
			else
			{
				printf("Pair %d : impossible.\n", count);
			}
		}
		printf("\n");
	}
	return 0;
}