#include <algorithm>
#include <iostream>
using namespace std;
char c[55][55];
int ms[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			c[i][j] = '.';
		}
	}
	while (k--)
	{
		int x, y;
		char col, dir;
		cin >> x >> y >> col >> dir;
		if (dir == 'U')
		{
			for (int i = x; i >= 1; i--)
			{
				c[i][y] = col;
			}
		}
		else if (dir == 'D')
		{
			for (int i = x; i <= n; i++)
			{
				c[i][y] = col;
			}
		}
		else if (dir == 'L')
		{
			for (int i = y; i >= 1; i--)
			{
				c[x][i] = col;
			}
		}
		else
		{
			for (int i = y; i <= m; i++)
			{
				c[x][i] = col;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << c[i][j];
		}
		cout << "\n";
	}
	return 0;
}