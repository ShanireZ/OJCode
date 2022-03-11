#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Gold
{
	int m, v;
	double b;
};
bool cmp(Gold x, Gold y)
{
	return x.b > y.b;
}
Gold d[105];
int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i].m >> d[i].v;
		d[i].b = 1.0 * d[i].v / d[i].m;
	}
	sort(d + 1, d + 1 + n, cmp);
	double tot = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t >= d[i].m)
		{
			tot += d[i].v;
			t -= d[i].m;
		}
		else
		{
			tot += t * d[i].b;
			break;
		}
	}
	cout << fixed << setprecision(2) << tot << endl;
	return 0;
}