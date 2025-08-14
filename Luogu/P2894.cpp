#include <algorithm>
#include <iostream>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
	int lc, rc, v, tag, lv, rv; //! 1住人 2清空
};
Node ns[100005];
int n, m, root, pos;
void update(int now, int l, int r)
{
	int mid = (l + r) / 2;
	ns[now].v = max({ns[LC].v, ns[RC].v, ns[LC].rv + ns[RC].lv});
	ns[now].lv = ns[LC].lv, ns[now].rv = ns[RC].rv;
	if (mid - l + 1 == ns[LC].v)
	{
		ns[now].lv += ns[RC].lv;
	}
	if (r - mid == ns[RC].v)
	{
		ns[now].rv += ns[LC].rv;
	}
}
void maketree(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = ns[now].lv = ns[now].rv = 1;
		return;
	}
	int mid = (l + r) / 2;
	maketree(LC, l, mid);
	maketree(RC, mid + 1, r);
	update(now, l, r);
}
void pushdown(int now, int l, int r)
{
	if (ns[now].tag == 1)
	{
		ns[LC].v = ns[LC].lv = ns[LC].rv = 0;
		ns[RC].v = ns[RC].lv = ns[RC].rv = 0;
		ns[LC].tag = ns[RC].tag = 1, ns[now].tag = 0;
	}
	else if (ns[now].tag == 2)
	{
		int mid = (l + r) / 2;
		ns[LC].v = ns[LC].lv = ns[LC].rv = mid - l + 1;
		ns[RC].v = ns[RC].lv = ns[RC].rv = r - mid;
		ns[LC].tag = ns[RC].tag = 2, ns[now].tag = 0;
	}
}
void edit(int now, int l, int r, int x, int y, int k)
{
	if (x <= l && y >= r)
	{
		if (k == 1)
		{
			ns[now].v = ns[now].lv = ns[now].rv = 0;
		}
		else
		{
			ns[now].v = ns[now].lv = ns[now].rv = r - l + 1;
		}
		ns[now].tag = k;
		return;
	}
	pushdown(now, l, r);
	int mid = (l + r) / 2;
	if (x <= mid)
	{
		edit(LC, l, mid, x, y, k);
	}
	if (y > mid)
	{
		edit(RC, mid + 1, r, x, y, k);
	}
	update(now, l, r);
}
int query(int now, int l, int r, int x)
{
	if (ns[now].lv >= x)
	{
		return l;
	}
	pushdown(now, l, r);
	int mid = (l + r) / 2;
	if (ns[LC].v >= x)
	{
		return query(LC, l, mid, x);
	}
	else if (ns[LC].rv + ns[RC].lv >= x)
	{
		return mid - ns[LC].rv + 1;
	}
	else
	{
		return query(RC, mid + 1, r, x);
	}
}
int main()
{
	cin >> n >> m;
	maketree(root, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int opt, x, y;
		cin >> opt >> x;
		if (opt == 1)
		{
			if (ns[root].v < x)
			{
				cout << 0 << endl;
				continue;
			}
			int p = query(root, 1, n, x);
			cout << p << endl;
			edit(root, 1, n, p, p + x - 1, 1);
		}
		else
		{
			cin >> y;
			edit(root, 1, n, x, x + y - 1, 2);
		}
	}
	return 0;
}