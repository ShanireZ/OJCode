#include <cstdio>
#include <algorithm>
using namespace std;
int read();
struct Node
{
	int lc, rc, len, mv, lmv, rmv, lzy; //lzy 0无事 1开房 2退房
};
Node ns[200005];
int root, pos;
void pushdown(int now)
{
	if (ns[now].lzy == 0)
	{
		return;
	}
	int lc = ns[now].lc, rc = ns[now].rc;
	if (ns[now].lzy == 1) // 开房标记
	{
		ns[lc].mv = ns[lc].lmv = ns[lc].rmv = 0;
		ns[rc].mv = ns[rc].lmv = ns[rc].rmv = 0;
	}
	else //退房标记
	{
		ns[lc].mv = ns[lc].lmv = ns[lc].rmv = ns[lc].len;
		ns[rc].mv = ns[rc].lmv = ns[rc].rmv = ns[rc].len;
	}
	ns[ns[now].lc].lzy = ns[ns[now].rc].lzy = ns[now].lzy;
	ns[now].lzy = 0;
}
void update(int now)
{
	int lc = ns[now].lc, rc = ns[now].rc;
	ns[now].len = ns[lc].len + ns[rc].len;
	ns[now].lmv = ns[lc].lmv;
	if (ns[lc].len == ns[lc].lmv)
	{
		ns[now].lmv += ns[rc].lmv;
	}
	ns[now].rmv = ns[rc].rmv;
	if (ns[rc].len == ns[rc].rmv)
	{
		ns[now].rmv += ns[lc].rmv;
	}
	ns[now].mv = max(max(ns[lc].mv, ns[rc].mv), ns[lc].rmv + ns[rc].lmv);
}
void newTree(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].len = ns[now].mv = ns[now].lmv = ns[now].rmv = 1;
		return;
	}
	int mid = (l + r) / 2;
	newTree(ns[now].lc, l, mid);
	newTree(ns[now].rc, mid + 1, r);
	update(now);
}
void edit(int now, int l, int r, int a, int b, int k)
{
	pushdown(now);
	if (a <= l && r <= b)
	{
		if (k == 1)
		{
			ns[now].mv = ns[now].lmv = ns[now].rmv = 0;
		}
		else
		{
			ns[now].mv = ns[now].lmv = ns[now].rmv = ns[now].len;
		}
		ns[now].lzy = k;
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid && b >= l)
	{
		edit(ns[now].lc, l, mid, a, b, k);
	}
	if (a <= r && b >= mid + 1)
	{
		edit(ns[now].rc, mid + 1, r, a, b, k);
	}
	update(now);
}
int querry(int now, int l, int r, int a)
{
	pushdown(now);
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	if (ns[ns[now].lc].mv >= a)
	{
		return querry(ns[now].lc, l, mid, a);
	}
	else if (ns[ns[now].lc].rmv + ns[ns[now].rc].lmv >= a)
	{
		return mid - ns[ns[now].lc].rmv + 1;
	}
	else
	{
		return querry(ns[now].rc, mid + 1, r, a);
	}
}
int main()
{
	// freopen("xxx.in", "r", stdin);
	// freopen("xxx.out", "w", stdout);
	int n = read(), m = read();
	newTree(root, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int t = read();
		if (t == 1)
		{
			int a = read();
			if (a > ns[root].mv)
			{
				printf("0\n");
				continue;
			}
			int p = querry(root, 1, n, a);
			printf("%d\n", p);
			edit(root, 1, n, p, p + a - 1, 1);
		}
		else
		{
			int a = read(), b = read();
			edit(root, 1, n, a, a + b - 1, 2);
		}
	}
	return 0;
}
int read()
{
	char ch = getchar();
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
	int t = 1, ans = 0;
	if (ch == '-')
	{
		t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return t * ans;
}