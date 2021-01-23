#include <iostream>
#include <cmath>
using namespace std;
int a[100][100], b[100][100];
int m, n, r, s;

void InputMatrix(int x, int y, bool state)
{
	if (state)
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> a[i][j];
			}
		}
	}
	else
	{
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> b[i][j];
			}
		}
	}
}

int CmpMatrix(int x, int y)
{
	int count = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			count += abs(a[x + i][y + j] - b[i][j]);
		}
	}
	return count;
}

void ChooseMatrix(int &x, int &y)
{
	int minDiffer = 1000001;
	for (int i = 0; i <= m - r; i++)
	{
		for (int j = 0; j <= n - s; j++)
		{
			int count = CmpMatrix(i, j);
			if (count < minDiffer)
			{
				minDiffer = count;
				x = i, y = j;
			}
		}
	}
}

int main()
{
	int posX, posY;
	cin >> m >> n;
	InputMatrix(m, n, 1);
	cin >> r >> s;
	InputMatrix(r, s, 0);
	ChooseMatrix(posX, posY);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << a[posX + i][posY + j] << " ";
		}
		cout << endl;
	}
	return 0;
}