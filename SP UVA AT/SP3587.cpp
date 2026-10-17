#include <algorithm>
#include <iostream>
using namespace std;
#define MX 10000000
int prim[MX + 5], vis[MX + 5], cnt;
void init()
{
	vis[1] = vis[0] = 1; // 1不是質數0是質數
	for (int i = 2; i <= MX; i++)
	{
		if (vis[i] == 0)
		{
			prim[++cnt] = i;
		}
		for (int j = 1; j <= cnt && prim[j] * i <= MX; j++)
		{
			vis[prim[j] * i] = 1;
			if (i % prim[j] == 0)
			{
				break;
			}
		}
	}
}
long long qpow(long long a, long long n, long long p) // 快速冪
{
	long long ans = 1;
	while (n)
	{
		if (n & 1)
		{
			ans = (__int128)ans * a % p; // 注意！中間結果可能溢出，需要使用__int128過渡
		}
		a = (__int128)a * a % p;
		n >>= 1;
	}
	return ans;
}
bool checkprime(long long x)
{
	if (x == 2 || x == 3)
	{
		return true;
	}
	if (x % 2 == 0 || (x % 6 != 5 && x % 6 != 1))
	{
		return false;
	}
	long long A[10] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, d = x - 1, r = 0;
	while (d % 2 == 0) // 算出d, r
	{
		d /= 2, r++;
	}
	for (int i = 0; i < 7; i++)
	{
		long long a = A[i];
		long long v = qpow(a, d, x); // a^d
		// 如果a^d≡0，說明是a是x的倍數；如果a^d≡1或-1，說明這串數接下來一定都是1，不用繼續計算
		if (v <= 1 || v == x - 1)
		{
			continue;
		}
		for (int i = 0; i < r; ++i)
		{
			v = (__int128)v * v % x;	  // 同樣使用__int128過渡
			if (v == x - 1 && i != r - 1) // 得到-1，說明接下來都是1，可以退出了
			{
				v = 1;
				break;
			}
			// 在中途而非開頭得到1，卻沒有經過-1，說明存在其他數字y≠-1滿足y^2≡1，則x一定不是奇素數
			if (v == 1)
			{
				return false;
			}
		}
		if (v != 1) // 查看是不是以1結尾
		{
			return false;
		}
	}
	return true;
}
int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		long long x;
		cin >> x;
		x -= 1;
		if (x <= MX)
		{
			int pos = lower_bound(prim + 1, prim + 1 + cnt, x) - prim;
			if (prim[pos] != x)
			{
				pos--;
			}
			cout << prim[pos] << endl;
		}
		else
		{
			while (checkprime(x) == 0)
			{
				x--;
			}
			cout << x << endl;
		}
	}
	return 0;
}