#include <iostream>
#include <cstring>
using namespace std;
long long base[3][3] = {{0, 0, 0}, {0, 1, 1}, {0, 1, 0}};
long long ans[3][3], op[3][3], mod = 1e9 + 7;
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
	long long n;
	cin >> n;
	if (n <= 2)
	{
		cout << 1;
	}
	else
	{
		for (int i = 1; i <= 2; i++) //op初始化为单位矩阵
		{
			for (int j = 1; j <= 2; j++)
			{
				if (i == j)
				{
					op[i][j] = 1;
				}
			}
		}
		n -= 2;
		while (n)
		{
			if (n & 1)
			{
				make(op, base, op);
			}
			n >>= 1;
			make(base, base, base);
		}
		long long tot = (op[1][1] + op[2][1]) % mod;
		cout << tot;
	}
	return 0;
}