//顺时针打印矩阵
#include <iostream>
using namespace std;

void PrintMatrixInCircle(int row, int col, int(*a)[4], int start)
{
	int endX = col - 1 - start;
	int endY = row - 1 - start;

	//从左向右打印
	for (int j = start; j <= endX; ++j)
	{
		cout << a[start][j] << " ";
	}
	//从上向下打印
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			cout << a[i][endX] << " ";
		}
	}
	//从右向左打印
	if (start < endX && start < endY)
	{
		for (int j = endX - 1; j >= start; --j)
		{
			cout << a[endY][j] << " ";
		}
	}
	//从下向上打印
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			cout << a[i][start] << " ";
		}
	}
}

void PrintMarixClockwisely(int row, int col, int(*a)[4])
{
	if (row <= 0 || col <= 0 || a == NULL)
	{
		return;
	}

	int start = 0;
	while (col > start * 2 && row > start * 2)
	{
		//循环继续的条件
		PrintMatrixInCircle(row, col, a, start);
		++start;
		//向内推进圈数
	}
	cout << endl;
}

int main()
{
	int a[][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	PrintMarixClockwisely(4, 4, a);
	return 0;
}