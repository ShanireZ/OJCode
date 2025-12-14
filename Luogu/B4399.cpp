#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int l, r;
	bool operator<(const Node &oth) const
	{
		return l > oth.l;
	}
};
Node ns[100005];
long long n, ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].l >> ns[i].r;
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1, now = 0; i <= n; i++)
	{
		if (ns[i].l <= now && ns[i].r >= now)
		{
			continue;
		}
		now = ns[i].l;
		ans += now;
	}
	cout << ans << endl;
	return 0;
}