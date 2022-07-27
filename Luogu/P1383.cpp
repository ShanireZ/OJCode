#include <iostream>
using namespace std;
#define MX 100005
int n, pos, hpos, his[MX], cnt[MX], root[MX];
struct Node
{
	int lc, rc;
	char v;
};
Node ns[MX * 40];
void edit(int old, int &now, int l, int r, int p, char x)
{
	now = ++pos;
	ns[now] = ns[old];
	if (l == r)
	{
		ns[now].v = x;
		return;
	}
	int mid = (l + r) / 2;
	(p <= mid) ? edit(ns[old].lc, ns[now].lc, l, mid, p, x) : edit(ns[old].rc, ns[now].rc, mid + 1, r, p, x);
}
char query(int now, int l, int r, int p)
{
	if (l == r)
	{
		return ns[now].v;
	}
	int mid = (l + r) / 2;
	return (p <= mid) ? query(ns[now].lc, l, mid, p) : query(ns[now].rc, mid + 1, r, p);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char opt;
		cin >> opt;
		if (opt == 'T')
		{
			char x;
			cin >> x;
			cnt[i] = cnt[i - 1] + 1;
			his[++hpos] = i;
			edit(root[i - 1], root[i], 1, n, cnt[i], x);
		}
		else if (opt == 'U')
		{
			int x;
			cin >> x;
			root[i] = root[his[hpos - x]];
			cnt[i] = cnt[his[hpos - x]];
			his[++hpos] = i;
		}
		else
		{
			int x;
			cin >> x;
			root[i] = root[i - 1];
			cnt[i] = cnt[i - 1];
			cout << query(root[i], 1, n, x) << endl;
		}
	}
	return 0;
}