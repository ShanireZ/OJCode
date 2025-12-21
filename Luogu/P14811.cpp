#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	long long l, r, w;
	bool operator<(const Node &oth) const
	{
		return w < oth.w;
	}
};
Node ns[100005];
long long n, m, res, ans, mn, hz[100005], hzv[100005];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].w >> ns[i].l >> ns[i].r;
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1; i <= n; i++)
	{
		res += ns[i].l * ns[i].w;
		m -= ns[i].l;
	}
	ans = res + m * ns[n].w;
	for (int i = n; i >= 1; i--)
	{
		hz[i] = hz[i + 1] + ns[i].r - ns[i].l;
		hzv[i] = hzv[i + 1] + (ns[i].r - ns[i].l) * ns[i].w;
	}
	for (int i = 1; i <= n; i++)
	{
		long long lmt = m + ns[i].l, l = 1, r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			hz[mid] >= lmt ? l = mid + 1 : r = mid - 1;
		}
		ans = max(ans, res + hzv[l] + (lmt - hz[l]) * ns[l - 1].w - ns[i].l * ns[i].w);
	}
	cout << ans << endl;
	return 0;
}