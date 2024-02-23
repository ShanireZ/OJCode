#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
// 将原点按角θ旋转  x' = xcosθ - ysinθ  y' = xsinθ + ycosθ
struct Node
{
	double x, y;
	bool operator<(const Node &oth) const
	{
		return x * y < oth.x * oth.y;
	}
};
Node ns[10005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n)
	{
		srand(time(0));
		double rnd = rand(), ans = 10000;
		for (int i = 1; i <= n; i++)
		{
			double x, y;
			cin >> x >> y;
			ns[i].x = x * cos(rnd) - y * sin(rnd), ns[i].y = x * sin(rnd) + y * cos(rnd);
		}
		sort(ns + 1, ns + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= i + 100 && j <= n; j++)
			{
				double dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
				ans = min(dis, ans);
			}
		}
		if (ans == 10000)
		{
			cout << "INFINITY\n";
		}
		else
		{
			cout << fixed << setprecision(4) << ans << "\n";
		}
		cin >> n;
	}
	return 0;
}