#include <iostream>
using namespace std;
struct Node
{
	int tag, lc, rc;
};
Node ns[400005];
int root, pos;
void maketree(int l, int r, int &now)
{
	now = ++pos;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	maketree(l, mid, ns[now].lc);
	maketree(mid + 1, r, ns[now].rc);
}
void pushdown(int now)
{
	if (ns[now].tag)
	{
		ns[now].tag = 0;
		ns[ns[now].lc].tag ^= 1;
		ns[ns[now].rc].tag ^= 1;
	}
}
void edit(int l, int r, int now, int x, int y)
{
	if (l == x && r == y)
	{
		ns[now].tag ^= 1;
		return;
	}
	//pushdown(now);
	int mid = (l + r) / 2;
	if (l <= y && mid >= x)
	{
		edit(l, mid, ns[now].lc, max(l, x), min(mid, y));
	}
	if (mid + 1 <= y && r >= x)
	{
		edit(mid + 1, r, ns[now].rc, max(mid + 1, x), min(r, y));
	}
}
void querry(int l, int r, int now, int x)
{
	if (l == r)
	{
		cout << ns[now].tag << endl;
		return;
	}
	pushdown(now);
	int mid = (l + r) / 2;
	if (l <= x && mid >= x)
	{
		querry(l, mid, ns[now].lc, x);
	}
	else
	{
		querry(mid + 1, r, ns[now].rc, x);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	maketree(1, n, root);
	for (int i = 1; i <= m; i++)
	{
		int op, x, y;
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y;
			edit(1, n, root, x, y);
		}
		else
		{
			cin >> x;
			querry(1, n, root, x);
		}
	}
	return 0;
}