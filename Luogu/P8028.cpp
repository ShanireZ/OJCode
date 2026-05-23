#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
int n, m, ans, cnt, pos, vis[100005], dis[100005];
void dfs(int now, int from)
{
	vis[now] = 1;
	for (int nxt : to[now])
	{
		if (nxt == from)
		{
			continue;
		}
		dis[nxt] = dis[now] + 1;
		if (dis[nxt] > dis[pos])
		{
			pos = nxt;
		}
		dfs(nxt, now);
	}
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
			pos = i, cnt++;
			dfs(i, 0);
			int x = pos;
			dis[x] = 0;
			dfs(x, 0);
			ans += dis[pos];
		}
	}
	cout << cnt + ans << endl;
	return 0;
}