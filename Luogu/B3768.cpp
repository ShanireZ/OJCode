#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
int main()
{
	long long S = read(), v0 = read(), dis = 0, tim = 0;
	int v1 = read(), t1 = read(), v2 = read(), t2 = read(), n = read();
	for (int i = 1; i <= n; i++)
	{
		int t = read();
		if (v0 * (t - tim) + dis >= S)
		{
			tim += ceil(1.0 * (S - dis) / v0), dis = S;
			break;
		}
		dis += v0 * (t - tim), tim = t;
		dis = max(0ll, dis - v1 * t1), tim += t1;
		t1 += t2, v1 += v2;
	}
	if (dis < S)
	{
		tim += ceil(1.0 * (S - dis) / v0);
	}
	int d = tim / 86400 + 20230401, h = tim % 86400 / 3600, m = tim % 3600 / 60, s = tim % 60;
	printf("%dat%02d:%02d:%02d", d, h, m, s);
	return 0;
}