#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
mt19937 rnd;
vector<int> ns[100005];
int read(), all[500005];
long long trans[500005], key[100005], mod = 999999999999999989ll;
int main()
{
	rnd.seed(time(0));
	int n = read(), q = read(), pos = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int m = read();
		for (int j = 1; j <= m; j++)
		{
			all[pos] = read();
			ns[i].push_back(all[pos]);
			pos++;
		}
	}
	sort(all, all + pos);
	pos = unique(all, all + pos) - all;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < (int)ns[i].size(); j++)
		{
			int x = lower_bound(all, all + pos, ns[i][j]) - all;
			if (trans[x] == 0)
			{
				__int128_t rd = rnd();
				trans[x] = rd * rnd() % mod;
			}
			key[i] = (key[i] + trans[x]) % mod;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int op = read(), x = read(), y = read();
		if (op == 1)
		{
			key[y] = (key[y] + key[x]) % mod;
		}
		else if (key[x] == key[y])
		{
			ans ^= i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}