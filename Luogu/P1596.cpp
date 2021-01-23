#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
char farm[105][105];
int vis[105][105];
int move[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++)
	{
		int nx = x + move[i][0];
		int ny = y + move[i][1];
		if(farm[nx][ny] == 'W' && vis[nx][ny] == 0)
		{
			dfs(nx, ny);
		}
	}	
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> farm[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(farm[i][j] == 'W' && vis[i][j] == 0)
			{
				dfs(i, j);
				ans++;
			}
		}	
	}
	cout << ans;	
	return 0;
}