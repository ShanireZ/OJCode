#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MX 10005
int n, m, npos, gpos, rdfn[MX], vis[MX], g[MX], ok[MX];
vector<int> to[MX], rto[MX];
set<int> s[MX];
void dfs(int now)
{
	vis[now] = 1;
	for (int i = 0; i < to[now].size(); i++)
	{
		int t = to[now][i];
		if (vis[t])
		{
			continue;
		}
		dfs(t);
	}
	rdfn[++npos] = now;
}
void rdfs(int now)
{
	vis[now] = 1, g[now] = gpos;
	s[gpos].insert(now);
	for (int i = 0; i < rto[now].size(); i++)
	{
		int t = rto[now][i];
		if (vis[t])
		{
			continue;
		}
		rdfs(t);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		to[u].push_back(v), rto[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			dfs(i);
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = n; i >= 1; i--)
	{
		int id = rdfn[i];
		if (vis[id] == 0)
		{
			gpos++;
			rdfs(id);
		}
	}
	cout << gpos << endl;
	for (int i = 1; i <= n; i++)
	{
		int gid = g[i];
		if (ok[gid] == 1)
		{
			continue;
		}
		ok[gid] = 1;
		for (auto it = s[gid].begin(); it != s[gid].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}