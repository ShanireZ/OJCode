#include <algorithm>
#include <cstdio>
using namespace std;
int read();
int pk[500005], root, pos;
struct Node
{
	int v, lmax, rmax, maxv, lc, rc;
};
Node ns[2000005];
void update(int now)
{
	int lc = ns[now].lc, rc = ns[now].rc;
	ns[now].v = ns[lc].v + ns[rc].v;
	ns[now].lmax = max(ns[lc].lmax, ns[lc].v + ns[rc].lmax);
	ns[now].rmax = max(ns[rc].rmax, ns[rc].v + ns[lc].rmax);
	ns[now].maxv = max(ns[lc].maxv, ns[rc].maxv);
	ns[now].maxv = max(ns[lc].rmax + ns[rc].lmax, ns[now].maxv);
}
void newNode(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = ns[now].lmax = ns[now].rmax = ns[now].maxv = pk[l];
		return;
	}
	int mid = (l + r) / 2;
	newNode(ns[now].lc, l, mid);
	newNode(ns[now].rc, mid + 1, r);
	update(now);
}
void edit(int now, int l, int r, int p, int k)
{
	if (l == r)
	{
		ns[now].v = ns[now].lmax = ns[now].rmax = ns[now].maxv = k;
		return;
	}
	int mid = (l + r) / 2;
	p <= mid ? edit(ns[now].lc, l, mid, p, k) : edit(ns[now].rc, mid + 1, r, p, k);
	update(now);
}
Node query(int now, int l, int r, int a, int b)
{
	if (a <= l && b >= r)
	{
		return ns[now];
	}
	int mid = (l + r) / 2;
	if (b <= mid)
	{
		return query(ns[now].lc, l, mid, a, b);
	}
	else if (a > mid)
	{
		return query(ns[now].rc, mid + 1, r, a, b);
	}
	else
	{
		Node nl = query(ns[now].lc, l, mid, a, b);
		Node nr = query(ns[now].rc, mid + 1, r, a, b);
		Node na;
		na.v = nl.v + nr.v;
		na.lmax = max(nl.lmax, nl.v + nr.lmax);
		na.rmax = max(nr.rmax, nr.v + nl.rmax);
		na.maxv = max(nl.maxv, nr.maxv);
		na.maxv = max(na.maxv, nl.rmax + nr.lmax);
		return na;
	}
}
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		pk[i] = read();
	}
	newNode(root, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int opt = read(), x = read(), y = read();
		if (opt == 1) // todo 查询
		{
			if (x > y)
			{
				swap(x, y);
			}
			printf("%d\n", query(root, 1, n, x, y).maxv);
		}
		else // todo 修改
		{
			edit(root, 1, n, x, y);
		}
	}
	return 0;
}
int read()
{
	int ans = 0, type = 1;
	char ch = getchar();
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
	if (ch == '-')
	{
		type = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans * type;
}