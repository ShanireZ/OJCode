#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read()
{
	char ch = getchar();
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
	int ans = 0, t = 1;
	if (ch == '-')
	{
		ch = getchar();
		t = -1;
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + (ch - '0');
		ch = getchar();
	}
	return ans * t;
}
struct Node //! 村子
{
	vector<int> to;
	vector<int> q;
	int g, fa, vis, root, ans;
};
Node ns[100005];
struct Segment //! 每个村子的线段树
{
	int maxt, maxv, lc, rc;
};
Segment seg[10000005];
struct Quest //! 每个lca询问
{
	int a, b, type, lca;
};
Quest qst[100005];
int pos;
int dfn(int now)
{
	if (now != ns[now].g)
	{
		ns[now].g = dfn(ns[now].g);
	}
	return ns[now].g;
}
void lca(int now)
{
	ns[now].vis = 1;
	//todo 遍历所有儿子
	for (int i = 0; i < ns[now].to.size(); i++)
	{
		int id = ns[now].to[i];
		if (id == ns[now].fa)
		{
			continue;
		}
		ns[id].fa = now;
		lca(id);
		ns[id].g = now; //todo 合并集合
	}
	//todo 遍历所有问题
	for (int i = 0; i < ns[now].q.size(); i++)
	{
		int qid = ns[now].q[i];
		int id = qst[qid].a + qst[qid].b - now;
		if (ns[id].vis)
		{
			qst[qid].lca = dfn(id);
		}
	}
}
void update(int now)
{
	if (seg[seg[now].lc].maxt >= seg[seg[now].rc].maxt)
	{
		seg[now].maxt = seg[seg[now].lc].maxt;
		seg[now].maxv = seg[seg[now].lc].maxv;
	}
	else
	{
		seg[now].maxt = seg[seg[now].rc].maxt;
		seg[now].maxv = seg[seg[now].rc].maxv;
	}
}
void edit(int &now, int l, int r, int p, int k)
{
	if (now == 0)
	{
		now = ++pos;
	}
	if (l == r)
	{
		seg[now].maxt += k;
		seg[now].maxv = l;
		return;
	}
	int mid = (l + r) / 2;
	p <= mid ? edit(seg[now].lc, l, mid, p, k) : edit(seg[now].rc, mid + 1, r, p, k);
	update(now);
}
void merge(int f, int &t, int l, int r)
{
	if (f == 0 || t == 0)
	{
		t ^= f;
		return;
	}
	if (l == r)
	{
		seg[t].maxt += seg[f].maxt;
		return;
	}
	int mid = (l + r) / 2;
	merge(seg[f].lc, seg[t].lc, l, mid);
	merge(seg[f].rc, seg[t].rc, mid + 1, r);
	update(t);
}
void dfs(int now)
{
	for (int i = 0; i < ns[now].to.size(); i++)
	{
		int id = ns[now].to[i];
		if (id == ns[now].fa)
		{
			continue;
		}
		dfs(id);
	}
	if (seg[ns[now].root].maxt > 0)
	{
		ns[now].ans = seg[ns[now].root].maxv;
	}
	merge(ns[now].root, ns[ns[now].fa].root, 1, 100000);
}
int main()
{
	int n = read(), m = read();
	for (int i = 1; i < n; i++)
	{
		ns[i].g = i;
		int x = read(), y = read();
		ns[x].to.push_back(y);
		ns[y].to.push_back(x);
	}
	ns[n].g = n;
	for (int i = 1; i <= m; i++)
	{
		qst[i].a = read(), qst[i].b = read(), qst[i].type = read();
		ns[qst[i].a].q.push_back(i);
		ns[qst[i].b].q.push_back(i);
	}
	lca(1);
	for (int i = 1; i <= m; i++)
	{
		edit(ns[qst[i].a].root, 1, 100000, qst[i].type, 1);
		edit(ns[qst[i].b].root, 1, 100000, qst[i].type, 1);
		edit(ns[qst[i].lca].root, 1, 100000, qst[i].type, -1);
		edit(ns[ns[qst[i].lca].fa].root, 1, 100000, qst[i].type, -1);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ns[i].ans);
	}
	return 0;
}