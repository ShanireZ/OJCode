#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, ans, mod = 998244353, a[505], fac[505], f[505][505][505];
string s;
int main()
{
	cin >> n >> m >> s;
	s.insert(s.begin(), '#');
	fac[0] = 1;
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		a[x]++;
		fac[i] = fac[i - 1] * i % mod;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '0')
		{
			for (int j = 1; j <= i; j++)
			{
				for (int k = 0; k <= i; k++)
				{
					f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k]) % mod;
				}
			}
		}
		else
		{
			for (int j = 0; j <= i; j++)
			{
				for (int k = 0; k <= i; k++)
				{
					long long x = a[j] - k;
					f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
					if (k > 0)
					{
						f[i][j][k] = (f[i][j][k] - f[i - 1][j][k - 1] * (x + 1) % mod + mod) % mod;
					}
					f[i][j + 1][k + 1] = (f[i][j + 1][k + 1] + x * f[i - 1][j][k]) % mod;
				}
			}
		}
	}
	for (int j = 0; j <= n - m; j++)
	{
		for (int k = 0; k <= n; k++)
		{
			ans = (ans + f[n][j][k] * fac[n - k]) % mod;
		}
	}
	cout << ans % mod << endl;
	return 0;
}