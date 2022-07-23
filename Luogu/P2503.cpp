#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
int n, m;
double dp[30][10], a[30], s[30], avg, ans = 1e50;
double make()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = 1e50;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i && j <= m; j++)
		{
			for (int k = 0; k < i; k++)
			{
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + (s[i] - s[k] - avg) * (s[i] - s[k] - avg));
			}
		}
	}
	return dp[n][m];
}
void SA(double cur)
{
	double T = 10000;
	while (T > 1e-5)
	{
		int x = rand() % n + 1, y = rand() % n + 1;
		if (x == y)
		{
			continue;
		}
		swap(a[x], a[y]);
		double now = make();
		if (now < cur || exp((ans - now) / T) * RAND_MAX > rand())
		{
			cur = now;
		}
		else
		{
			swap(a[x], a[y]);
		}
		T *= 0.995;
	}
	ans = min(ans, cur);
}
int main()
{
	srand(time(0));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		avg += a[i];
	}
	avg /= m;
	while ((double)clock() / CLOCKS_PER_SEC <= 0.9)
	{
		// random_shuffle(a + 1, a + 1 + n);
		SA(make());
	}
	cout << fixed << setprecision(2) << sqrt(ans / m) << endl;
	return 0;
}