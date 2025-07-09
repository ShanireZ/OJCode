#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int lc, rc, v; //! 上方作为tag用 叶节点作为值用
};
Node ns[200005];
int n, m, root, pos;
void maketree(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	maketree(ns[now].lc, l, mid);
	maketree(ns[now].rc, mid + 1, r);
}
void pushdown(int now, int l, int r)
{
	if (ns[now].v == 1)
	{
		ns[ns[now].lc].v ^= 1, ns[ns[now].rc].v ^= 1;
		ns[now].v = 0;
	}
}
void edit(int now, int l, int r, int x, int y)
{
	if (x <= l && y >= r)
	{
		ns[now].v ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(now, l, r);
	if (x <= mid)
	{
		edit(ns[now].lc, l, mid, x, y);
	}
	if (y > mid)
	{
		edit(ns[now].rc, mid + 1, r, x, y);
	}
}
int query(int now, int l, int r, int x)
{
	if (l == r)
	{
		return ns[now].v;
	}
	int mid = (l + r) / 2;
	pushdown(now, l, r);
	if (x <= mid)
	{
		return query(ns[now].lc, l, mid, x);
	}
	else
	{
		return query(ns[now].rc, mid + 1, r, x);
	}
}
int main()
{
	cin >> n >> m;
	maketree(root, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int t, l, r;
		cin >> t >> l;
		if (t == 1)
		{
			cin >> r;
			edit(root, 1, n, l, r);
		}
		else
		{
			cout << query(root, 1, n, l) << endl;
		}
	}
	return 0;
}