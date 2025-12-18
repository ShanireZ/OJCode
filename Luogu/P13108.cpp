#include <algorithm>
#include <iostream>
using namespace std;
string s;
int trie[50005][30], t[50005], T, n, pos;
void init()
{
	int now = 1;
	for (int i = (int)s.size() - 1; i >= 0; i--)
	{
		int x = s[i] - 'A';
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
		t[now]++;
	}
}
int dfs(int now)
{
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (t[trie[now][i]] > 1)
		{
			cnt += dfs(trie[now][i]);
		}
	}
	if (t[now] - cnt >= 2)
	{
		cnt += 2;
	}
	return cnt;
}
int main()
{
	cin >> T;
	for (int j = 1; j <= T; j++)
	{
		cin >> n;
		pos = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> s;
			init();
		}
		cout << "Case #" << j << ": " << dfs(1) << endl;
		for (int i = 1; i <= pos; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				trie[i][j] = 0;
			}
			t[i] = 0;
		}
	}
	return 0;
}