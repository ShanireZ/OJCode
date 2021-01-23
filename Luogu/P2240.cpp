#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Node
{
	int m, v;
	double x;
	void countx()
	{
		x = 1.0 * v / m;
	}
};
Node ns[105];
bool cmp(Node a, Node b)
{
	return a.x > b.x;
}
int main()
{
	int n, t;
	double ans = 0;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].m >> ns[i].v;
		ns[i].countx();
	}
	sort(ns + 1, ns + 1 + n, cmp);
	for (int i = 1; i <= n && t > 0; i++)
	{
		int take = min(ns[i].m, t);
		ans += take * ns[i].x;
		t -= take;
	}
	cout << fixed << setprecision(2) << ans;
	return 0;
}