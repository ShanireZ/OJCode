#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[200005];
vector<int> dc;
struct Node
{
	int l, r, v;
};
Node ns[8000005];
int root[200005];
int pos;
int find_id(int x)
{
	return lower_bound(dc.begin(), dc.end(), x) - dc.begin() + 1;
}
void edit(int l, int r, int old, int &now, int x)
{
	now = ++pos;
	ns[now] = ns[old];
	ns[now].v++;
	if (l == r)
	{
		return;
	}
	int mid = (l + r) >> 1;
	if (x <= mid)
	{
		edit(l, mid, ns[old].l, ns[now].l, x);
	}
	else
	{
		edit(mid + 1, r, ns[old].r, ns[now].r, x);
	}
}
int find_k(int l, int r, int old, int now, int k)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) >> 1;
	int left = ns[ns[now].l].v - ns[ns[old].l].v;
	if (k <= left)
	{
		return find_k(l, mid, ns[old].l, ns[now].l, k);
	}
	else
	{
		return find_k(mid + 1, r, ns[old].r, ns[now].r, k - left);
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dc.push_back(a[i]);
	}
	sort(dc.begin(), dc.end());
	dc.erase(unique(dc.begin(), dc.end()), dc.end());
	for (int i = 1; i <= n; i++)
	{
		edit(1, dc.size(), root[i - 1], root[i], find_id(a[i]));
	}
	for (int i = 1; i <= m; i++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << dc[find_k(1, dc.size(), root[l - 1], root[r], k) - 1] << endl;
	}
	return 0;
}