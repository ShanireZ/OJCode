#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, pos, root = 1, mx, fin[155], t[10505], d[10505], fail[10505], trie[10505][26];
string s[155];
queue<int> q;
void init(int i)
{
	int now = root;
	for (char ch : s[i])
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
	while (n)
	{
		pos = 1, mx = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			init(i);
		}
		failt();
		cin >> s[0];
		int now = root;
		for (char ch : s[0])
		{
			int x = ch - 'a';
			now = findpos(now, x);
			t[now]++;
		}
		tp();
		for (int i = 1; i <= n; i++)
		{
			mx = max(mx, t[fin[i]]);
		}
		cout << mx << endl;
		for (int i = 1; i <= n; i++)
		{
			if (t[fin[i]] == mx)
			{
				cout << s[i] << endl;
			}
		}
		cin >> n;
		fill(fin, fin + 1 + n, 0);
		for (int i = 1; i <= pos; i++)
		{
			fill(trie[i], trie[i] + 26, 0);
			t[i] = d[i] = fail[i] = 0;
		}
	}
	return 0;
}