#include <cstdio>
#include <algorithm>
using namespace std;
int read();
struct Node
{
	int lc, rc, sum, lmv, rmv, mv;
};
Node ns[2000005];
int pos, root, score[500005];
void update(int now)
{
	ns[now].sum = ns[ns[now].lc].sum + ns[ns[now].rc].sum;
	ns[now].lmv = max(ns[ns[now].lc].lmv, ns[ns[now].lc].sum + ns[ns[now].rc].lmv);
	ns[now].rmv = max(ns[ns[now].rc].rmv, ns[ns[now].rc].sum + ns[ns[now].lc].rmv);
	ns[now].mv = max(ns[ns[now].lc].mv, ns[ns[now].rc].mv);
	ns[now].mv = max(ns[now].mv, ns[ns[now].lc].rmv + ns[ns[now].rc].lmv);
}
void newNode(int &now, int l, int r)
{
	now = ++pos;
	if (l == r)
	{
		ns[now].sum = ns[now].mv = ns[now].lmv = ns[now].rmv = score[l];
		return;
	}
	int mid = (l + r) / 2;
	newNode(ns[now].lc, l, mid);
	newNode(ns[now].rc, mid + 1, r);
	update(now);
}
void edit(int now, int l, int r, int p, int s)
{
	if (l == r)
	{
		ns[now].sum = ns[now].mv = ns[now].lmv = ns[now].rmv = s;
		return;
	}
	int mid = (l + r) / 2;
	if (p <= mid)
	{
		edit(ns[now].lc, l, mid, p, s);
	}
	else
	{
		edit(ns[now].rc, mid + 1, r, p, s);
	}
	update(now);
}
Node querry(int now, int l, int r, int a, int b)
{
	if (a <= l && b >= r)
	{
		return ns[now];
	}
	int mid = (l + r) / 2;
	if (b <= mid)
	{
		return querry(ns[now].lc, l, mid, a, b);
	}
	else if (a > mid)
	{
		return querry(ns[now].rc, mid + 1, r, a, b);
	}
	else
	{
		Node n1 = querry(ns[now].lc, l, mid, a, b);
		Node n2 = querry(ns[now].rc, mid + 1, r, a, b);
		Node ans;
		ans.sum = n1.sum + n2.sum;
		ans.lmv = max(n1.lmv, n1.sum + n2.lmv);
		ans.rmv = max(n2.rmv, n1.rmv + n2.sum);
		ans.mv = max(n1.mv, n2.mv);
		ans.mv = max(ans.mv, n1.rmv + n2.lmv);
		return ans;
	}
}
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		score[i] = read();
	}
	newNode(root, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int t = read(), a = read(), b = read();
		if (t == 1) //todo 查
		{
			if (a > b)
			{
				swap(a, b);
			}
			printf("%d\n", querry(root, 1, n, a, b).mv);
		}
		else //todo 改
		{
			edit(root, 1, n, a, b);
		}
	}
	return 0;
}
int read()
{
	char ch = getchar();
	int ans = 0, t = 1;
	while (ch != '-' && (ch > '9' || ch < '0'))
	{
		ch = getchar();
	}
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