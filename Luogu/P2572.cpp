#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int lc, rc, v1, lv1, rv1, c1, v0, lv0, rv0, c0, tag; // tag 1变1 2变0 3反转 0不变
};
Node ns[200005];
int n, m, root, pos, ans, pre, a[100005];
void update(int now, int l, int r)
{
	int mid = (l + r) / 2;
	ns[now].v1 = max(max(ns[ns[now].lc].v1, ns[ns[now].rc].v1), ns[ns[now].lc].rv1 + ns[ns[now].rc].lv1);
	ns[now].v0 = max(max(ns[ns[now].lc].v0, ns[ns[now].rc].v0), ns[ns[now].lc].rv0 + ns[ns[now].rc].lv0);
	ns[now].c1 = ns[ns[now].lc].c1 + ns[ns[now].rc].c1;
	ns[now].c0 = ns[ns[now].lc].c0 + ns[ns[now].rc].c0;
	ns[now].lv1 = ns[ns[now].lc].lv1, ns[now].rv1 = ns[ns[now].rc].rv1;
	if (ns[ns[now].lc].v1 == mid - l + 1)
	{
		ns[now].lv1 += ns[ns[now].rc].lv1;
	}
	if (ns[ns[now].rc].v1 == r - mid)
	{
		ns[now].rv1 += ns[ns[now].lc].rv1;
	}
	ns[now].lv0 = ns[ns[now].lc].lv0, ns[now].rv0 = ns[ns[now].rc].rv0;
	if (ns[ns[now].lc].v0 == mid - l + 1)
	{
		ns[now].lv0 += ns[ns[now].rc].lv0;
	}
	if (ns[ns[now].rc].v0 == r - mid)
	{
		ns[now].rv0 += ns[ns[now].lc].rv0;
	}
}
void maketree(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].c1 = ns[now].v1 = ns[now].lv1 = ns[now].rv1 = a[l];
		ns[now].c0 = ns[now].v0 = ns[now].lv0 = ns[now].rv0 = !a[l];
		return;
	}
	int mid = (l + r) / 2;
	maketree(ns[now].lc, l, mid), maketree(ns[now].rc, mid + 1, r);
	update(now, l, r);
}
void pushdown(int now, int l, int r)
{
	int mid = (l + r) / 2;
	if (ns[now].tag == 1)
	{
		ns[ns[now].lc].tag = ns[ns[now].rc].tag = 1;
		ns[ns[now].lc].v1 = ns[ns[now].lc].lv1 = ns[ns[now].lc].rv1 = ns[ns[now].lc].c1 = mid - l + 1;
		ns[ns[now].rc].v1 = ns[ns[now].rc].lv1 = ns[ns[now].rc].rv1 = ns[ns[now].rc].c1 = r - mid;
		ns[ns[now].lc].c1 = mid - l + 1, ns[ns[now].rc].c1 = r - mid;
		ns[ns[now].lc].v0 = ns[ns[now].lc].lv0 = ns[ns[now].lc].rv0 = ns[ns[now].lc].c0 = 0;
		ns[ns[now].rc].v0 = ns[ns[now].rc].lv0 = ns[ns[now].rc].rv0 = ns[ns[now].rc].c0 = 0;
		ns[ns[now].lc].c0 = 0, ns[ns[now].rc].c0 = 0;
	}
	else if (ns[now].tag == 2)
	{
		ns[ns[now].lc].tag = ns[ns[now].rc].tag = 2;
		ns[ns[now].lc].v1 = ns[ns[now].lc].lv1 = ns[ns[now].lc].rv1 = ns[ns[now].lc].c1 = 0;
		ns[ns[now].rc].v1 = ns[ns[now].rc].lv1 = ns[ns[now].rc].rv1 = ns[ns[now].rc].c1 = 0;
		ns[ns[now].lc].c1 = 0, ns[ns[now].rc].c1 = 0;
		ns[ns[now].lc].v0 = ns[ns[now].lc].lv0 = ns[ns[now].lc].rv0 = ns[ns[now].lc].c0 = mid - l + 1;
		ns[ns[now].rc].v0 = ns[ns[now].rc].lv0 = ns[ns[now].rc].rv0 = ns[ns[now].rc].c0 = r - mid;
		ns[ns[now].lc].c0 = mid - l + 1, ns[ns[now].rc].c0 = r - mid;
	}
	else if (ns[now].tag == 3)
	{
		ns[ns[now].lc].tag = 3 - ns[ns[now].lc].tag, ns[ns[now].rc].tag = 3 - ns[ns[now].rc].tag;
		swap(ns[ns[now].lc].v1, ns[ns[now].lc].v0), swap(ns[ns[now].lc].c1, ns[ns[now].lc].c0);
		swap(ns[ns[now].lc].lv1, ns[ns[now].lc].lv0), swap(ns[ns[now].lc].rv1, ns[ns[now].lc].rv0);
		swap(ns[ns[now].rc].v1, ns[ns[now].rc].v0), swap(ns[ns[now].rc].c1, ns[ns[now].rc].c0);
		swap(ns[ns[now].rc].lv1, ns[ns[now].rc].lv0), swap(ns[ns[now].rc].rv1, ns[ns[now].rc].rv0);
	}
	ns[now].tag = 0;
}
void edit(int now, int l, int r, int x, int y, int k)
{
	if (x <= l && y >= r)
	{
		if (k == 3)
		{
			swap(ns[now].c1, ns[now].c0), swap(ns[now].v1, ns[now].v0);
			swap(ns[now].lv1, ns[now].lv0), swap(ns[now].rv1, ns[now].rv0);
			ns[now].tag = 3 - ns[now].tag;
		}
		else if (k == 2)
		{
			ns[now].tag = k;
			ns[now].v1 = ns[now].lv1 = ns[now].rv1 = ns[now].c1 = 0;
			ns[now].v0 = ns[now].lv0 = ns[now].rv0 = ns[now].c0 = r - l + 1;
		}
		else
		{
			ns[now].tag = k;
			ns[now].v1 = ns[now].lv1 = ns[now].rv1 = ns[now].c1 = r - l + 1;
			ns[now].v0 = ns[now].lv0 = ns[now].rv0 = ns[now].c0 = 0;
		}
		return;
	}
	pushdown(now, l, r);
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		edit(ns[now].lc, l, mid, x, y, k);
	}
	if (y > mid)
	{
		edit(ns[now].rc, mid + 1, r, x, y, k);
	}
	update(now, l, r);
}
int queryc(int now, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
	{
		return ns[now].c1;
	}
	pushdown(now, l, r);
	int mid = (l + r) / 2, ans = 0;
	if (x <= mid)
	{
		ans += queryc(ns[now].lc, l, mid, x, y);
	}
	if (y > mid)
	{
		ans += queryc(ns[now].rc, mid + 1, r, x, y);
	}
	return ans;
}
void queryv(int now, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
	{
		ans = max(ans, max(ns[now].v1, ns[now].lv1 + pre));
		if (ns[now].c1 == r - l + 1)
		{
			pre += ns[now].rv1;
		}
		else
		{
			pre = ns[now].rv1;
		}
		return;
	}
	pushdown(now, l, r);
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		queryv(ns[now].lc, l, mid, x, y);
	}
	if (y > mid)
	{
		queryv(ns[now].rc, mid + 1, r, x, y);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	maketree(root, 1, n);
	while (m--)
	{
		int opt, x, y;
		cin >> opt >> x >> y;
		x++, y++;
		if (opt == 0)
		{
			edit(root, 1, n, x, y, 2);
		}
		else if (opt == 1)
		{
			edit(root, 1, n, x, y, 1);
		}
		else if (opt == 2)
		{
			edit(root, 1, n, x, y, 3);
		}
		else if (opt == 3)
		{
			cout << queryc(root, 1, n, x, y) << endl;
		}
		else
		{
			ans = pre = 0;
			queryv(root, 1, n, x, y);
			cout << ans << endl;
		}
	}
	return 0;
}