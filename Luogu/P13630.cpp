#include <algorithm>
#include <iostream>
using namespace std;
string s;
int trie[300005][26], cnt[300005], n, k, ans, pos = 1;
void init()
{
	int now = 1;
	cnt[1]++;
	for (char ch : s)
	{
		int x = ch - 'a';
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
		cnt[now]++;
	}
}
int dfs(int now)
{
	if (cnt[now] <= k)
	{
		int res = cnt[now];
		ans++, cnt[now] = 0;
		return res;
	}
	int tot = 0;
	while (cnt[now] > k)
	{
		int mx = 0;
		for (int i = 1; i < 26; i++)
		{
			if (cnt[trie[now][i]] > cnt[trie[now][mx]])
			{
				mx = i;
			}
		}
		int res = dfs(trie[now][mx]);
		cnt[now] -= res, tot += res;
	}
	return tot;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		init();
	}
	dfs(1);
	cout << ans + (cnt[1] != 0) << endl;
	return 0;
}