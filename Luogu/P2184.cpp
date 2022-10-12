#include <iostream>
using namespace std;
#define MX 100005
int n, m, st[MX], ed[MX];
int lowbit(int x)
{
	return x & -x;
}
void edit(int l, int r)
{
	while (l <= MX)
	{
		st[l]++;
		l += lowbit(l);
	}
	while (r <= MX)
	{
		ed[r]++;
		r += lowbit(r);
	}
}
int query(int x, int y)
{
	int cst = 0, ced = 0;
	while (y)
	{
		cst += st[y];
		y -= lowbit(y);
	}
	while (x)
	{
		ced += ed[x];
		x -= lowbit(x);
	}
	return cst - ced;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1)
		{
			edit(l, r);
		}
		else
		{
			cout << query(l - 1, r) << endl;
		}
	}
	return 0;
}