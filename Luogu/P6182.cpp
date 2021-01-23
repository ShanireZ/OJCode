#include <iostream>
using namespace std;
int root[80005], top[80005], pos;
struct Node
{
	int l, r, v;
};
Node ns[3200005];
void edit(int l, int r, int old, int &now, int p, int x) //修改第p只牛为x
{
	now = ++pos;
	ns[now] = ns[old];
	if (l == r)
	{
		ns[now].v = x;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
	{
		edit(l, m, ns[old].l, ns[now].l, p, x);
	}
	else
	{
		edit(m + 1, r, ns[old].r, ns[now].r, p, x);
	}
}
int findx(int l, int r, int p, int x) //查找第x只牛的编号
{
	if (l == r)
	{
		return ns[p].v;
	}
	int m = (l + r) >> 1;
	if (x <= m)
	{
		return findx(l, m, ns[p].l, x);
	}
	else
	{
		return findx(m + 1, r, ns[p].r, x);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char type;
		int x;
		cin >> type;
		if (type == 'a')
		{
			cin >> x;
			top[i] = top[i - 1] + 1;
			edit(1, n, root[i - 1], root[i], top[i], x);
		}
		else if (type == 's')
		{
			top[i] = top[i - 1] - 1;
			edit(1, n, root[i - 1], root[i], top[i - 1], 0);
		}
		else
		{
			cin >> x;
			top[i] = top[x - 1];
			root[i] = root[x - 1];
		}
		if (top[i] == 0) //没牛了
		{
			cout << -1 << endl;
			continue;
		}
		cout << findx(1, n, root[i], top[i]) << endl;
	}
	return 0;
}