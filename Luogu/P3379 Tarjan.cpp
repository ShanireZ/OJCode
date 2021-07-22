#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
	int fa, g, vis, dp;
	vector<int> to;
	vector<int> qs;
};
Node ns[500005];
struct Quest
{
	int all, ans;
};
Quest qst[500005];
int dfn(int x)
{
	if (x != ns[x].g)
	{
		ns[x].g = dfn(ns[x].g);
	}
	return ns[x].g;
}
void dfs(int now, int dp)
{
	ns[now].vis = 1;
	ns[now].dp = dp;
	for (int i = 0; i < ns[now].to.size(); i++)
	{
		int id = ns[now].to[i];
		if (id == ns[now].fa)
		{
			continue;
		}
		ns[id].fa = now;
		dfs(id, dp + 1);
		ns[id].g = now;
	}
	for (int i = 0; i < ns[now].qs.size(); i++)
	{
		int qid = ns[now].qs[i];
		int id = qst[qid].all - now;
		if (ns[id].vis == 1)
		{
			qst[qid].ans = dfn(id);
		}
	}
}
int main()
{
	int n = read(), m = read(), s = read();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		ns[i].g = i;
		ns[x].to.push_back(y);
		ns[y].to.push_back(x);
	}
	ns[n].g = n;
	for (int i = 1; i <= m; i++)
	{
		int x = read(), y = read();
		qst[i].all = x + y;
		ns[x].qs.push_back(i);
		ns[y].qs.push_back(i);
	}
	dfs(s, 1);
	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", qst[i].ans);
	}
	return 0;
}
int read()
{
	char ch = getchar();
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
	int t = 1, ans = 0;
	if (ch == '-')
	{
		t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return t * ans;
}