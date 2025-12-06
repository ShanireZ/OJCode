#include <algorithm>
#include <iostream>
using namespace std;
string s[10005];
long long n, m, ans = 1, base = 233, mod = 1e9 + 7, bod[10005], hsh[10005];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int j = 0; j < m; j++) // 每列哈希压缩成一个元素
	{
		for (int i = 0; i < n; i++)
		{
			hsh[j] = (hsh[j] * base + s[i][j]) % mod;
		}
	}
	for (int i = 1, j = 0; i < m; i++) // 列的最小循环节
	{
		while (j != 0 && hsh[i] != hsh[j])
		{
			j = bod[j - 1];
		}
		bod[i] = (hsh[i] == hsh[j] ? ++j : 0);
	}
	ans = ans * (m - bod[m - 1]);
	for (int i = 0; i < n; i++) // 每行哈希压缩成一个元素
	{
		hsh[i] = 0;
		for (int j = 0; j < m; j++)
		{
			hsh[i] = (hsh[i] * base + s[i][j]) % mod;
		}
	}
	for (int i = 1, j = 0; i < n; i++) // 行的最小循环节
	{
		while (j != 0 && hsh[i] != hsh[j])
		{
			j = bod[j - 1];
		}
		bod[i] = (hsh[i] == hsh[j] ? ++j : 0);
	}
	ans = ans * (n - bod[n - 1]);
	cout << ans << endl;
	return 0;
}