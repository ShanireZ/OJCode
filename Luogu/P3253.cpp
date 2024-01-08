#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int p, op;
};
Node ns[200005];
int a[3][100005], v[3][100005], n[3];
vector<int> all;
int lowbit(int x)
{
	return x & -x;
}
void edit(int x, int op, int k)
{
	while (x <= n[op])
	{
		v[op][x] += k, x += lowbit(x);
	}
}
int query(int x, int op)
{
	int res = 0;
	while (x > 0)
	{
		res += v[op][x], x -= lowbit(x);
	}
	return res;
}
int main()
{
	cin >> n[1] >> n[2];
	for (int i = 1; i <= n[1]; i++)
	{
		cin >> a[1][i];
		all.push_back(a[1][i]), edit(i, 1, 1);
	}
	for (int i = 1; i <= n[2]; i++)
	{
		cin >> a[2][i];
		all.push_back(a[2][i]), edit(i, 2, 1);
	}
	sort(all.begin(), all.end());
	for (int i = 1; i <= n[1]; i++)
	{
		a[1][i] = lower_bound(all.begin(), all.end(), a[1][i]) - all.begin() + 1;
		ns[a[1][i]].p = i, ns[a[1][i]].op = 1;
	}
	for (int i = 1; i <= n[2]; i++)
	{
		a[2][i] = lower_bound(all.begin(), all.end(), a[2][i]) - all.begin() + 1;
		ns[a[2][i]].p = i, ns[a[2][i]].op = 2;
	}
	long long ans = 0, lop = ns[n[1] + n[2]].op, lp = 0;
	for (int i = n[1] + n[2]; i > 0; i--)
	{
		edit(ns[i].p, ns[i].op, -1);
		if (ns[i].op == lop)
		{
			ans += abs(query(ns[i].p, ns[i].op) - query(lp, ns[i].op));
		}
		else
		{
			ans += query(ns[i].p, ns[i].op) + query(lp, lop);
		}
		lp = ns[i].p, lop = ns[i].op;
	}
	cout << ans << endl;
	return 0;
}
// TAG: 树状数组 线段树 逆序对