#include <algorithm>
#include <iostream>
using namespace std;
int n, m, len, pos = 1, t[500005], f[500005], trie[500005][2];
void init()
{
	int now = 1, x;
	for (int i = 1; i <= len; i++)
	{
		cin >> x;
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
		t[now]++;
	}
	f[now]++;
}
int query()
{
	int now = 1, res = 0, x;
	for (int i = 1; i <= len; i++)
	{
		cin >> x;
		if (trie[now][x] == 0)
		{
			while (i < len)
			{
				cin >> x;
				i++;
			}
			return res;
		}
		now = trie[now][x];
		res += f[now];
	}
	return res + t[now] - f[now];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> len;
		init();
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> len;
		cout << query() << endl;
	}
	return 0;
}