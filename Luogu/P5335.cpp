#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s;
int trie[6000005][10], dt[6000005], n, root = 1, pos = 1;
long long lans;
vector<int> st[6000005];
void add(int id)
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
		if (dt[now])
		{
			dt[now]--;
		}
		else
		{
			st[now].push_back(id);
		}
	}
}
void del()
{
	int now = root;
	for (char ch : s)
	{
		int x = ch - 'a';
		now = trie[now][x];
		dt[now]++;
	}
}
int query()
{
	int now = root;
	for (char ch : s)
	{
		int x = ch - 'a';
		now = trie[now][x];
	}
	return now;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int opt, a, b, c;
		cin >> opt >> s;
		if (opt == 1)
		{
			add(i);
		}
		else if (opt == 2)
		{
			del();
		}
		else
		{
			cin >> a >> b >> c;
			long long num = (a * abs(lans) + b) % c, p = query();
			lans = ((long long)st[p].size() <= num ? -1 : st[p][num]);
			cout << lans << endl;
		}
	}
	return 0;
}