#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;
struct Node
{
	double x, y;
	bool operator<(const Node &oth) const
	{
		return x * y < oth.x * oth.y;
	}
};
Node ns[100005];
mt19937 rnd(time(0));
double ans1 = 1e20, ans2;
int main()
{
	int n, d = rnd();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		ns[i] = Node{x * cos(d) - y * sin(d), x * sin(d) + y * cos(d)};
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n && j <= i + 15; j++)
		{
			double dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
			ans1 = min(ans1, dis);
		}
		for (int j = n; j >= 1 && j >= n - 15; j--)
		{
			double dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
			ans2 = max(ans2, dis);
		}
	}
	cout << fixed << setprecision(2) << ans1 << " " << ans2 << endl;
	return 0;
}