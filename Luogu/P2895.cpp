#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int ns[310][310];
int vis[310][310];
int moves[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int mint = 0x3f3f3f3f;
void dfs(int x, int y, int step)
{
	if (ns[x][y] == -1) //!到达安全点
	{
		mint = min(mint, step);
		return;
	}
	vis[x][y] = step; //!记录最小步数
	if (step >= mint) //!剪枝-如果时间已经超了
	{
		return;
	}
	for (int i = 1; i < 5; i++)
	{
		int nx = x + moves[i][0];
		int ny = y + moves[i][1];
		//!不能出界 不能走到已被摧毁的点 剪枝-到达该点步数较之前更多
		if (nx >= 0 && ny >= 0 && (ns[nx][ny] == -1 || ns[nx][ny] > step + 1) && vis[nx][ny] > step + 1)
		{
			dfs(nx, ny, step + 1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	memset(ns, -1, sizeof(ns));
	memset(vis, 127, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		for (int j = 0; j < 5; j++)
		{
			int nx = x + moves[j][0];
			int ny = y + moves[j][1];
			//!不能出界 ns记录最早摧毁时间
			if (nx >= 0 && ny >= 0 && (ns[nx][ny] == -1 || ns[nx][ny] > t))
			{
				ns[nx][ny] = t;
			}
		}
	}
	dfs(0, 0, 0);
	if (mint == 0x3f3f3f3f)
	{
		mint = -1;
	}
	cout << mint;
	return 0;
}