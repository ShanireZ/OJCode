#include <iostream>
#include <cstring>
using namespace std;
long long n, mod = 1e9 + 7, k;
long long base[105][105], ans[105][105], op[105][105];
void make(long long a[][105], long long b[][105], long long c[][105])
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				ans[i][j] += a[i][k] * b[k][j] % mod;
				ans[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			c[i][j] = ans[i][j];
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> base[i][j];
			if (i == j)
			{
				op[i][j] = 1; //初始op为单位矩阵 任何矩阵乘单位矩阵结果为原矩阵
			}
		}
	}
	while (k)
	{
		if (k & 1)
		{
			make(op, base, op);
		}
		k >>= 1;
		make(base, base, base);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << op[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}