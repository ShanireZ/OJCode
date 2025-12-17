#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	long long a, t;
};
Node ns[100005];
bool cmp(Node x, Node y)
{
	return x.a < y.a;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].a >> ns[i].t;
	}
	sort(ns + 1, ns + n + 1, cmp);
	long long ans = ns[n].a * 2, ex = 0;
	for (int i = n; i >= 1; i--)
	{
		ex = max(ex, ns[i].t - (ns[n].a + ns[n].a - ns[i].a));
	}
	cout << ans + ex << endl;
	return 0;
}