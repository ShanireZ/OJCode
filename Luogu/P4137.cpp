#include <algorithm>
#include <iostream>
using namespace std;
#define MX 200005
struct Quest
{
	int l, r, id;
	bool operator<(const Quest oth) const
	{
		return r < oth.r;
	}
};
Quest q[MX];
struct Node
{
	int p, lc, rc;
};
Node ns[MX * 4];
int n, m, root, pos, a[MX], ans[MX];
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
void edit(int now, int l, int r, int x, int p)
{
	if (l == r)
	{
		ns[now].p = p;
		return;
	}
	int mid = (l + r) / 2;
	(x <= mid) ? edit(ns[now].lc, l, mid, x, p) : edit(ns[now].rc, mid + 1, r, x, p);
	ns[now].p = min(ns[ns[now].lc].p, ns[ns[now].rc].p);
}
int query(int now, int l, int r, int p)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	return (ns[ns[now].lc].p < p) ? query(ns[now].lc, l, mid, p) : query(ns[now].rc, mid + 1, r, p);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort(q + 1, q + 1 + m);
	init(root, 0, 200000);
	pos = 0;
	for (int i = 1; i <= m; i++)
	{
		while (pos < q[i].r)
		{
			pos++;
			edit(root, 0, 200000, a[pos], pos);
		}
		ans[q[i].id] = query(root, 0, 200000, q[i].l);
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}