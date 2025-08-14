#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, m, ans, sum, vis[100005], zc[100005], cc[100005];
void dfs(int now)
{
	vis[now] = 1;
	for (int nxt : to[now])
	{
		if (vis[nxt])
		{
			continue;
		}
		dfs(nxt);
		if (zc[now] < zc[nxt] + 1)
		{
			cc[now] = zc[now];
			zc[now] = zc[nxt] + 1;
		}
		else if (cc[now] < zc[nxt] + 1)
		{
			cc[now] = zc[nxt] + 1;
		}
	}
	ans = max(zc[now] + cc[now], ans);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			ans = 0, dfs(i);
			sum += ans + 1;
		}
	}
	cout << sum << endl;
	return 0;
}