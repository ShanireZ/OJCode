#include <iostream>
using namespace std;
long long powmod(long long mod, long long pow, long long base)
{
	long long ans = 1;
	while (pow)
	{
		if (pow & 1 == 1)
		{
			ans = ans * base % mod;
		}
		base = base * base % mod;
		pow >>= 1;
	}
	return ans;
}
int main()
{
	long long n;
	cin >> n;
	long long ans = powmod(9999991, n - 2, n);
	for (int i = n - 1; i >= 1; i--)
	{
		ans = ans * i % 9999991;
	}
	cout << ans;
	return 0;
}