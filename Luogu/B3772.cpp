#include <iostream>
using namespace std;
int mp[200][200];
int main()
{
	int n, m, k, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			mp[i + 50][j + 50] = (ch == '#');
		}
	}
	for (int i = 51; i <= n + 50; i++)
	{
		for (int j = 51; j <= m + 50; j++)
		{
			if (mp[i][j] != 1)
			{
				continue;
			}
			for (int x = k; x >= 0; x--)
			{
				for (int y = x - k; y <= k - x; y++)
				{
					int nx = i - x, ny = j + y;
					if (mp[nx][ny] == 0)
					{
						mp[nx][ny] = 2, cnt++;
					}
				}
			}
			for (int x = k; x >= 0; x--)
			{
				for (int y = x - k; y <= k - x; y++)
				{
					int nx = i + x, ny = j + y;
					if (mp[nx][ny] == 0)
					{
						mp[nx][ny] = 2, cnt++;
					}
				}
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}