#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read();
struct Node
{
	vector<int> to;
	vector<int> qst;
	int root, g, vis, fa, ans;
};
Node ns[100005]; //图
struct Segment
{
	int lc, rc, v, maxv, maxt;
};
Segment seg[10000005]; //线段树
struct Quest
{
	int a, b, lca, type;
};
Quest quest[100005]; //lca询问
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
	for (int i = 0; i < ns[now].to.size(); i++)
	{
		int id = ns[now].to[i];
		if (ns[now].fa == id)
		{
			continue;
		}
		ns[id].fa = now;
		lca(id);
		ns[id].g = now;
	}
	for (int i = 0; i < ns[now].qst.size(); i++)
	{
		int qid = ns[now].qst[i];
		int id = quest[qid].a + quest[qid].b - now;
		if (ns[id].vis)
		{
			quest[qid].lca = dfn(id);
		}
	}
}
void update(int now)
{
	seg[now].v = seg[seg[now].lc].v + seg[seg[now].rc].v;
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
		seg[now].v += k;
		seg[now].maxt = seg[now].v;
		seg[now].maxv = l;
		return;
	}
	int mid = (l + r) / 2;
	p <= mid ? edit(seg[now].lc, l, mid, p, k) : edit(seg[now].rc, mid + 1, r, p, k);
	update(now);
}
void merge(int nowf, int &nowt, int l, int r)
{
	if (nowf == 0 || nowt == 0)
	{
		nowt |= nowf;
		return;
	}
	if (l == r)
	{
		seg[nowt].v += seg[nowf].v;
		seg[nowt].maxt = seg[nowt].v;
		return;
	}
	int mid = (l + r) / 2;
	merge(seg[nowf].lc, seg[nowt].lc, l, mid);
	merge(seg[nowf].rc, seg[nowt].rc, mid + 1, r);
	update(nowf), update(nowt);
}
void dfs(int now)
{
	for (int i = 0; i < ns[now].to.size(); i++)
	{
		int id = ns[now].to[i];
		if (ns[now].fa == id)
		{
			continue;
		}
		dfs(id);
	}
	ns[now].ans = seg[ns[now].root].maxv;
	if (seg[ns[now].root].maxt <= 0)
	{
		ns[now].ans = 0;
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
		quest[i].a = read(), quest[i].b = read(), quest[i].type = read();
		ns[quest[i].a].qst.push_back(i);
		ns[quest[i].b].qst.push_back(i);
	}
	lca(1);
	for (int i = 1; i <= m; i++)
	{
		edit(ns[quest[i].a].root, 1, 100000, quest[i].type, 1);
		edit(ns[quest[i].b].root, 1, 100000, quest[i].type, 1);
		edit(ns[quest[i].lca].root, 1, 100000, quest[i].type, -1);
		edit(ns[ns[quest[i].lca].fa].root, 1, 100000, quest[i].type, -1);
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ns[i].ans);
	}
	return 0;
}
int read()
{
	char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9'))
	{
		ch = getchar();
	}
	int t = 1, ans = 0;
	if (ch == '-')
	{
		ch = getchar();
		t = -1;
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return t * ans;
}