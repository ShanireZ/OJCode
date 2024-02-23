#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
// 将原点按角θ旋转
// x' = xcosθ - ysinθ
// y' = xsinθ + ycosθ
struct Node
{
	double v;
	int id;
	bool operator<(const Node &b) const
	{
		return v < b.v;
	}
};
Node ns[400005];
long long pos[400005][2], n, ans = 1e18;
int main()
{
	ios::sync_with_stdio(false);
	srand(time(0));
	double rnd = rand();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos[i][0] = x, pos[i][1] = y, ns[i].id = i;
		ns[i].v = (x * cos(rnd) - y * sin(rnd)) * (x * sin(rnd) + y * cos(rnd));
	}
	sort(ns + 1, ns + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= i + 100 && j <= n; j++)
		{
			long long a = (pos[ns[i].id][0] - pos[ns[j].id][0]), b = (pos[ns[i].id][1] - pos[ns[j].id][1]);
			ans = min(a * a + b * b, ans);
		}
	}
	cout << ans << endl;
	return 0;
}