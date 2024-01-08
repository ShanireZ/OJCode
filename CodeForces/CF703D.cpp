#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define MX 1000005
struct Node
{
	int l, r, id;
	bool operator<(const Node &oth) const
	{
		return r < oth.r;
	}
};
Node ns[MX];
map<int, int> last;
int n, m, a[MX], v[MX], qz[MX], p[MX], ans[MX];
int lowbit(int x)
{
	return x & -x;
}
void edit(int x, int k)
{
	if (x != 0)
	{
		while (x <= n)
		{
			v[x] ^= k, x += lowbit(x);
		}
	}
}
int query(int x)
{
	int res = 0;
	while (x > 0)
	{
		res ^= v[x], x -= lowbit(x);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		qz[i] = qz[i - 1] ^ a[i];
		p[i] = last[a[i]], last[a[i]] = i;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> ns[i].l >> ns[i].r;
		ns[i].id = i;
	}
	sort(ns + 1, ns + m + 1);
	int pos = 0;
	for (int i = 1; i <= m; i++)
	{
		while (pos < ns[i].r)
		{
			pos++;
			edit(p[pos], a[pos]), edit(pos, a[pos]);
		}
		ans[ns[i].id] = (qz[ns[i].r] ^ qz[ns[i].l - 1]) ^ (query(ns[i].r) ^ query(ns[i].l - 1));
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}
// TAG: 树状数组 线段树 异或和 权值离线