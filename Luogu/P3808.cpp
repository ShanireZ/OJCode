#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MX 1000005
int trie[MX][26], t[MX], fin[MX], d[MX], fail[MX], n, ans, pos = 1, root = 1;
string s;
queue<int> q;
void init(int i)
{
	int now = root;
	for (char ch : s)
	{
		int x = ch - 'a';
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
	}
	fin[i] = now;
}
int findpos(int now, int x)
{
	while (now != 0 && trie[now][x] == 0)
	{
		now = fail[now];
	}
	return now == 0 ? root : trie[now][x];
}
void failt()
{
	q.push(root);
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			int nxt = trie[now][i];
			int f = findpos(fail[now], i);
			if (nxt == 0)
			{
				trie[now][i] = f;
				continue;
			}
			fail[nxt] = f, d[f]++, q.push(nxt);
		}
	}
}
void tp()
{
	for (int i = 1; i <= pos; i++)
	{
		if (d[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int now = q.front();
		q.pop();
		int nxt = fail[now];
		t[nxt] += t[now], d[nxt]--;
		if (d[nxt] == 0)
		{
			q.push(nxt);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		init(i);
	}
	failt();
	cin >> s;
	int now = root;
	for (char ch : s)
	{
		int x = ch - 'a';
		now = findpos(now, x);
		t[now]++;
	}
	tp();
	for (int i = 1; i <= n; i++)
	{
		ans += (t[fin[i]] != 0);
	}
	cout << ans << endl;
	return 0;
}