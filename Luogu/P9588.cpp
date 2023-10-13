#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	long long x, y, mv, sz;
	int lc, rc, tag;
};
Node ns[800005];
int root, pos, c, q, info[200005][2];
void init(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	init(ns[now].lc, l, mid), init(ns[now].rc, mid + 1, r);
}
void pushdown(int now)
{
	if (ns[now].tag)
	{
		ns[ns[now].lc].tag = ns[ns[now].rc].tag = 1, ns[now].tag = 0;
		ns[ns[now].lc].sz = ns[ns[now].rc].sz = ns[ns[now].lc].mv = ns[ns[now].rc].mv = 0;
		ns[ns[now].lc].x = ns[ns[now].rc].x = ns[ns[now].lc].y = ns[ns[now].rc].y = 0;
	}
}
void add(int now, int l, int r, int x, long long k)
{
	if (l == r)
	{
		ns[now].x = 1, ns[now].y = ns[now].mv = ns[now].sz = k;
		return;
	}
	pushdown(now);
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		add(ns[now].lc, l, mid, x, k);
	}
	else
	{
		add(ns[now].rc, mid + 1, r, x, k);
	}
	ns[now].mv = max(ns[ns[now].lc].mv, ns[ns[now].rc].mv);
	ns[now].sz = ns[ns[now].lc].sz + ns[ns[now].rc].sz;
}
void reduce(int now, int l, int r, long long &k)
{
	if (ns[now].sz <= k)
	{
		k -= ns[now].sz, ns[now].tag = 1;
		ns[now].sz = ns[now].mv = ns[now].x = ns[now].y = 0;
		return;
	}
	if (l == r)
	{
		ns[now].x += k, ns[now].sz -= k, k = 0;
		return;
	}
	pushdown(now);
	int mid = (l + r) / 2;
	reduce(ns[now].lc, l, mid, k);
	if (k)
	{
		reduce(ns[now].rc, mid + 1, r, k);
	}
	ns[now].mv = max(ns[ns[now].lc].mv, ns[ns[now].rc].mv);
	ns[now].sz = ns[ns[now].lc].sz + ns[ns[now].rc].sz;
}
long long queryk(int now, int l, int r, long long k)
{
	if (l == r)
	{
		return ns[now].x + k - 1;
	}
	pushdown(now);
	int mid = (l + r) / 2;
	if (k <= ns[ns[now].lc].sz)
	{
		return queryk(ns[now].lc, l, mid, k);
	}
	else
	{
		return queryk(ns[now].rc, mid + 1, r, k - ns[ns[now].lc].sz);
	}
}
int main()
{
	cin >> c >> q;
	init(root, 1, q);
	for (int i = 1; i <= q; i++)
	{
		long long opt, x;
		cin >> opt;
		if (opt == 1)
		{
			cin >> x;
			add(root, 1, q, i, x);
		}
		else if (opt == 2)
		{
			cin >> x;
			reduce(root, 1, q, x);
		}
		else if (opt == 3)
		{
			cin >> x;
			cout << queryk(root, 1, q, x) << endl;
		}
		else
		{
			cout << ns[root].mv << endl;
		}
	}
	return 0;
}