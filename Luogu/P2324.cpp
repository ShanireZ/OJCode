#include <iostream>
using namespace std;
int ms[10][2] = {{0}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int ans[10][10] = {{0}, {0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1}, {0, 0, 0, 5, 1, 1}, {0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}};
int now[10][10], mins, ok;
void dfs(int x, int y, int step, int pref)
{
	int cnt = 0;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cnt += (now[i][j] != ans[i][j]);
		}
	}
	if (cnt == 0)
	{
		ok = 1;
		return;
	}
	else if (cnt - 1 + step > mins)
	{
		return;
	}
	for (int i = 1; i <= 8; i++)
	{
		int nx = x + ms[i][0], ny = y + ms[i][1];
		if (nx > 5 || ny > 5 || nx < 1 || ny < 1 || i + pref == 9)
		{
			continue;
		}
		swap(now[x][y], now[nx][ny]);
		dfs(nx, ny, step + 1, i);
		swap(now[nx][ny], now[x][y]);
		if (ok)
		{
			return;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int sx = 1, sy = 1;
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				char ch;
				cin >> ch;
				now[i][j] = ch - '0';
				if (ch == '*')
				{
					sx = i, sy = j, now[i][j] = 5;
				}
			}
		}
		ok = 0, mins = 0;
		while (mins <= 15)
		{
			dfs(sx, sy, 0, 100);
			if (ok)
			{
				break;
			}
			mins++;
		}
		if (ok == 0)
		{
			mins = -1;
		}
		cout << mins << endl;
	}
	return 0;
}