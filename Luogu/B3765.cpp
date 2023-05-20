#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
int link[1005][105], vis[1005], ans;
int main()
{
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		link[i][0] = read();
		for (int j = 1; j <= link[i][0]; j++)
		{
			link[i][j] = read();
		}
	}
	ans = 1, vis[1] = 1;
	for (int i = 1; i <= link[1][0]; i++)
	{
		int now = link[1][i];
		ans += (!vis[now]), vis[now] = 1;
		for (int j = 1; j <= link[now][0]; j++)
		{
			int nxt = link[now][j];
			ans += (!vis[nxt]), vis[nxt] = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}