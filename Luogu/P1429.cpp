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
};
Node ns[200005];
bool cmp(Node a, Node b)
{
	return a.x < b.x;
}
int main()
{
	srand(time(0));
	double rnd = rand(), ans = 2e9;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		ns[i].x = x * cos(rnd) - y * sin(rnd), ns[i].y = x * sin(rnd) + y * cos(rnd);
	}
	sort(ns + 1, ns + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= i + 10 && j <= n; j++)
		{
			double dis = sqrt(pow(ns[i].x - ns[j].x, 2) + pow(ns[i].y - ns[j].y, 2));
			ans = min(dis, ans);
		}
	}
	cout << fixed << setprecision(4) << ans;
	return 0;
}