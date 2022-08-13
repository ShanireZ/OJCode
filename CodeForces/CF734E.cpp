#include <iostream>
#include <queue>
using namespace std;
#define MX 200005
int n, pos, root = 1, ans, col[MX], vis[MX], dis[MX], last[MX], pre[MX * 2], to[MX * 2];
queue<int> q;
void addEdge(int u, int v, int id)
{
	pre[id] = last[u], to[id] = v;
	last[u] = id;
}
void dp(int now)
{
	vis[now] = 1, dis[now] = 0;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (vis[t] == 0)
		{
			dp(t);
			ans = max(ans, dis[now] + (col[now] != col[t]) + dis[t]);
			dis[now] = max(dis[now], (col[now] != col[t]) + dis[t]);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> col[i];
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge(x, y, ++pos);
		addEdge(y, x, ++pos);
	}
	dp(root);
	cout << (ans + 1) / 2 << endl;
	return 0;
}