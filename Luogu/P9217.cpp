#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[100005], read();
int main()
{
	int n = read(), p = read(), q = read(), s = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	int pos = upper_bound(a + 1, a + 1 + n, a[n] - s) - a;
	double x = 1.0 * p / q;
	double y = 1.0 * (q - p) / q;
	double ans = pow(y, n - pos + 1) * a[n]; // a[n]最大
	for (int i = pos; i <= n; i++)			 // a[i]+s最大
	{
		ans += (a[i] + s) * x * pow(y, n - i);
	}
	printf("1\n%f", ans);
	return 0;
}
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