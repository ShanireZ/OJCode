#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005], root[1000005], pos;
struct Node
{
	int l, r, v;
};
Node ns[40000005];
void edit(int l, int r, int old, int &now, int p, int x)
{
	now = ++pos;
	ns[now] = ns[old];
	if (l == r)
	{
		ns[now].v = x;
		return;
	}
	int mid = (l + r) >> 1;
	if (p <= mid)
	{
		edit(l, mid, ns[old].l, ns[now].l, p, x);
	}
	else
	{
		edit(mid + 1, r, ns[old].r, ns[now].r, p, x);
	}
}
int find_p(int l, int r, int now, int p)
{
	if (l == r)
	{
		return ns[now].v;
	}
	int mid = (l + r) >> 1;
	if (p <= mid)
	{
		return find_p(l, mid, ns[now].l, p);
	}
	else
	{
		return find_p(mid + 1, r, ns[now].r, p);
	}
}
void make(int l, int r, int &now)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].v = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	make(l, mid, ns[now].l);
	make(mid + 1, r, ns[now].r);
}
int read() //快读
{
	char ch = getchar();
	while ((ch > '9' || ch < '0') && ch != '-')
	{
		ch = getchar();
	}
	int t = 1, n = 0;
	if (ch == '-')
	{
		t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		n = n * 10 + ch - '0';
		ch = getchar();
	}
	return n * t;
}
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	make(1, n, root[0]);
	for (int i = 1; i <= m; i++)
	{
		int ver = read(), t = read(), loc = read();
		if (t == 1)
		{
			int x = read();
			edit(1, n, root[ver], root[i], loc, x);
		}
		else
		{
			root[i] = root[ver];
			printf("%d\n", find_p(1, n, root[ver], loc));
		}
	}
	return 0;
}