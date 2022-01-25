#include <iostream>
using namespace std;
char mp[105][105];
int vis[105][105];
int n, m, ans, f[10][2] = {{0, 1}, {1, 1}, {-1, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1}, {-1, -1}};
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + f[i][0], ny = y + f[i][1];
		if (nx < 1 || ny < 1 || nx > n || ny > m)
		{
			continue;
		}
		if (vis[nx][ny] == 1 || mp[nx][ny] == '.')
		{
			continue;
		}
		dfs(nx, ny);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mp[i][j] == '.' || vis[i][j] == 1)
			{
				continue;
			}
			dfs(i, j);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}