#include <iostream>
#include <cstring>
using namespace std;
long long mod = 1e8;
long long base[3][3] = {{0, 0, 0}, {0, 1, 1}, {0, 1, 0}};
long long ans[3][3], op[3][3];
long long gcd(long long x, long long y)
{
	long long r;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
void make(long long a[][3], long long b[][3], long long c[][3])
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			for (int k = 1; k <= 2; k++)
			{
				ans[i][j] += a[i][k] * b[k][j] % mod;
				ans[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			c[i][j] = ans[i][j];
		}
	}
}
int main()
{
	long long n, m;
	cin >> n >> m;
	n = gcd(n, m) - 2;
	if (n <= 0)
	{
		cout << 1;
	}
	else
	{
		for (int i = 1; i <= 2; i++)
		{
			for (int j = 1; j <= 2; j++)
			{
				if (i == j)
				{
					op[i][j] = 1;
				}
			}
		}
		while (n)
		{
			if (n & 1)
			{
				make(op, base, op);
			}
			make(base, base, base);
			n >>= 1;
		}
		cout << (op[1][1] + op[2][1]) % mod;
	}
	return 0;
}