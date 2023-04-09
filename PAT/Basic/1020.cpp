#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Node
{
	double cnt, tot, p;
};
Node ns[1005];
bool cmp(Node a, Node b)
{
	return a.p > b.p;
}
int main()
{
	int n;
	double d, ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].cnt;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].tot;
		ns[i].p = ns[i].tot / ns[i].cnt;
	}
	sort(ns + 1, ns + 1 + n, cmp);
	for (int i = 1; i <= n && d; i++)
	{
		if (d >= ns[i].cnt)
		{
			ans += ns[i].tot, d -= ns[i].cnt;
		}
		else
		{
			ans += ns[i].tot / ns[i].cnt * d, d = 0;
		}
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}