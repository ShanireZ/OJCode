#include <iostream>
#include <cstring>
using namespace std;
long long base[3][3], ans[3][3], op[3][3];
long long p, q, m, n, a1, a2;
void make(long long a[][3], long long b[][3], long long c[][3])
{
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			for (int k = 1; k <= 2; k++)
			{
				ans[i][j] += a[i][k] * b[k][j] % m;
				ans[i][j] %= m;
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
	cin >> p >> q >> a1 >> a2 >> n >> m;
	base[1][1] = p, base[2][1] = q, base[1][2] = 1; //base初始化
	if (n == 1)
	{
		cout << a1;
	}
	else if (n == 2)
	{
		cout << a2;
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
		long long tot = (op[1][1] * a2 % m + op[2][1] * a1 % m) % m;
		cout << tot;
	}
	return 0;
}