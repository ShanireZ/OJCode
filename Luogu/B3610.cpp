#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 50005
int epos, npos, spos, gpos, n, m;
int last[MX], dfn[MX], low[MX], s[MX], to[MX * 12], pre[MX * 12];
vector<int> g[MX];
void addEdge(int u, int v, int id)
{
	pre[id] = last[u], to[id] = v;
	last[u] = id;
}
bool cmp(vector<int> a, vector<int> b)
{
	int x = a.size(), y = b.size();
	for (int i = 0; i < min(x, y); i++)
	{
		if (a[i] == b[i])
		{
			continue;
		}
		return a[i] < b[i];
	}
	return a.size() < b.size();
}
void tarjan(int now)
{
	dfn[now] = low[now] = ++npos;
	s[++spos] = now;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (dfn[t] == 0)
		{
			tarjan(t);
			low[now] = min(low[now], low[t]);
			if (dfn[now] <= low[t])
			{
				g[++gpos].push_back(now);
				while (s[spos] != t)
				{
					g[gpos].push_back(s[spos--]);
				}
				g[gpos].push_back(s[spos--]);
				sort(g[gpos].begin(), g[gpos].end());
			}
		}
		else
		{
			low[now] = min(low[now], dfn[t]);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
		{
			continue;
		}
		addEdge(a, b, ++epos), addEdge(b, a, ++epos);
	}
	for (int i = 1; i <= n; i++)
	{
		spos = 0;
		if (dfn[i] == 0)
		{
			tarjan(i);
		}
	}
	sort(g + 1, g + 1 + gpos, cmp);
	cout << gpos << endl;
	for (int i = 1; i <= gpos; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}