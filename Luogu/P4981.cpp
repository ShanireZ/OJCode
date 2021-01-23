#include <iostream>
#include <algorithm>
using namespace std;
//Cayley公式:n个节点共能形成n^n-2个无根树，以每个节点为根，那么能形成n^n-1个有根树
long long powmod(long long mod, long long pow, long long base) //快速幂
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
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		long long n;
		cin >> n;
		cout << powmod(1e9 + 9, n - 1, n) << endl;
	}
	return 0;
}