#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
	int v, w;
};
vector<Edge> es[100005];
int n, ans, pos = 1, bs[100005][35], trie[3100005][2];
void init(int p, int val)
{
	for (int i = 0; i <= 30; i++)
	{
		bs[p][i] = val % 2;
		val /= 2;
	}
	int now = 1;
	for (int i = 30; i >= 0; i--)
	{
		int x = bs[p][i];
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
	}
}
void dfs(int now, int from, int val)
{
	init(now, val);
	for (Edge e : es[now])
	{
		if (e.v == from)
		{
			continue;
		}
		dfs(e.v, now, val ^ e.w);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		es[u].push_back(Edge{v, w});
		es[v].push_back(Edge{u, w});
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		int res = 0, now = 1;
		for (int j = 30; j >= 0; j--)
		{
			int x = bs[i][j];
			res *= 2;
			trie[now][1 - x] ? now = trie[now][1 - x], res++ : now = trie[now][x];
		}
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}