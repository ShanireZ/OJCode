#include <iostream>
#include <cstring>
using namespace std;
long long mod = 1e9 + 7;
void count(long long a[][3], long long b[][3], long long c[][3]) //矩阵乘法a*b=c
{
	long long ans[3][3];
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j] % mod) % mod;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = ans[i][j];
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tz = 1; tz <= t; tz++)
	{
		int n;
		cin >> n;
		if (n <= 3)
		{
			cout << 1 << endl;
			continue;
		}
		n -= 3;
		long long base[3][3] = {{0, 0, 1}, {1, 0, 0}, {0, 1, 1}};
		long long op[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
		while (n) //base^n
		{
			if (n & 1)
			{
				count(op, base, op);
			}
			n >>= 1;
			count(base, base, base);
		}
		//an = st*op[all][2] ---> st={1,1,1}
		cout << (op[0][2] + op[1][2] + op[2][2]) % mod << endl;
	}
	return 0;
}