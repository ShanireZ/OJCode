#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int lc, rc, v;
};
Node ns[800005];
int n, m, root, pos, num[200005];
void maketree(int l, int r, int &now)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = num[l];
		return;
	}
	int mid = (l + r) / 2;
	maketree(l, mid, ns[now].lc);
	maketree(mid + 1, r, ns[now].rc);
	ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
void edit(int l, int r, int now, int x, int k)
{
	if (l == r)
	{
		ns[now].v = max(ns[now].v, k);
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= x)
	{
		edit(l, mid, ns[now].lc, x, k);
	}
	else
	{
		edit(mid + 1, r, ns[now].rc, x, k);
	}
	ns[now].v = max(ns[ns[now].lc].v, ns[ns[now].rc].v);
}
int querry(int l, int r, int now, int x, int y)
{
	if (l == x && r == y)
	{
		return ns[now].v;
	}
	int mid = (l + r) / 2;
	int ans = 0;
	if (l <= y && mid >= x)
	{
		ans = max(ans, querry(l, mid, ns[now].lc, max(l, x), min(mid, y)));
	}
	if (mid + 1 <= y && r >= x)
	{
		ans = max(ans, querry(mid + 1, r, ns[now].rc, max(mid + 1, x), min(r, y)));
	}
	return ans;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	maketree(1, n, root);
	for (int i = 1; i <= m; i++)
	{
		char opt;
		int x, y;
		cin >> opt >> x >> y;
		if (opt == 'Q')
		{
			cout << querry(1, n, root, x, y) << endl;
		}
		else
		{
			edit(1, n, root, x, y);
		}
	}
	return 0;
}