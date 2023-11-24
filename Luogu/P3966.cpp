#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 1000005
int trie[MX][30], fail[MX], ind[MX], cnt[MX], ed[205], root, pos, n;
string s;
queue<int> q;
void maketrie(int x)
{
	int now = root;
	for (char c : s)
	{
		int id = c - 'a';
		if (trie[now][id] == 0)
		{
			trie[now][id] = ++pos;
		}
		now = trie[now][id], cnt[now]++;
	}
	ed[x] = now;
}
int findpos(int now, int x)
{
	while (now != 0 && trie[now][x] == 0)
	{
		now = fail[now];
	}
	return now == 0 ? root : trie[now][x];
}
void makefail()
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
			}
			else
			{
				fail[nxt] = f, ind[f]++, q.push(nxt);
			}
		}
	}
}
void topo()
{
	for (int i = 1; i <= pos; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}
	while (q.size())
	{
		int now = q.front();
		q.pop();
		int f = fail[now];
		cnt[f] += cnt[now], ind[f]--;
		if (ind[f] == 0)
		{
			q.push(f);
		}
	}
}
int main()
{
	cin >> n;
	root = ++pos;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		maketrie(i);
	}
	makefail();
	topo();
	for (int i = 1; i <= n; i++)
	{
		cout << cnt[ed[i]] << endl;
	}
	return 0;
}
// TAG: AC自动机 字符串