#include <algorithm>
#include <iostream>
using namespace std;
#define MX 500005
struct Node
{
	int v, lc, rc, tag;
};
Node ns[MX * 4];
int n, q, root, pos, bpos, p[MX], a[MX], bk[MX], bkp[MX], opt[MX][2];
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
void update(int now)
{
	ns[now].v = min(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void init(int l, int r, int &now)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = a[l];
		return;
	}
	int mid = (l + r) / 2;
	init(l, mid, ns[now].lc);
	init(mid + 1, r, ns[now].rc);
	update(now);
}
void pushdown(int now)
{
	int lc = ns[now].lc, rc = ns[now].rc, tag = ns[now].tag;
	if (ns[now].tag)
	{
		ns[lc].v += tag, ns[rc].v += tag;
		ns[lc].tag += tag, ns[rc].tag += tag;
		ns[now].tag = 0;
	}
}
void edit(int l, int r, int x, int y, int now, int ex)
{
	if (x <= l && y >= r)
	{
		ns[now].v += ex, ns[now].tag += ex;
		return;
	}
	pushdown(now);
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		edit(l, mid, x, y, ns[now].lc, ex);
	}
	if (y > mid)
	{
		edit(mid + 1, r, x, y, ns[now].rc, ex);
	}
	update(now);
}
int query(int l, int r, int x, int y, int now)
{
	if (x <= l && y >= r)
	{
		return ns[now].v;
	}
	pushdown(now);
	int mid = (l + r) / 2, ans = 1e9;
	if (x <= mid)
	{
		ans = min(ans, query(l, mid, x, y, ns[now].lc));
	}
	if (y > mid)
	{
		ans = min(ans, query(mid + 1, r, x, y, ns[now].rc));
	}
	update(now);
	return ans;
}
void check()
{
	if (query(1, n, 1, n, root))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}
int main()
{
	n = read(), q = read();
	for (int i = 1; i <= n; i++)
	{
		p[i] = read();
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		if (a[i] == 1)
		{
			bk[++bpos] = i;
			bkp[bpos] = p[i];
		}
	}
	init(1, n, root);
	check();
	for (int i = 1; i <= q; i++)
	{
		int op = read();
		if (op == 1)
		{
			int l = read(), r = read(); // 下面查询时 l r 可能越界不存在
			opt[i][0] = min(bk[lower_bound(bkp + 1, bkp + 1 + bpos, l) - bkp], n);
			opt[i][1] = max(bk[upper_bound(bkp + 1, bkp + 1 + bpos, r) - bkp - 1], 1);
			edit(1, n, opt[i][0], opt[i][1], root, 1);
		}
		else
		{
			int x = read();
			edit(1, n, opt[x][0], opt[x][1], root, -1);
		}
		check();
	}
	return 0;
}