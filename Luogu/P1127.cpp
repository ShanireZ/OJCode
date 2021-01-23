#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s[1005];
int vis[1005], st[30], ed[30], n, trig;
void dfs(int x, int len, string str)
{
	if (len == n)
	{
		cout << str.substr(0, str.size() - 1);
		trig = 1;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0 && s[i][0] == s[x][s[x].size() - 1])
		{
			vis[i] = 1;
			dfs(i, len + 1, str + s[i] + ".");
			vis[i] = 0;
			if (trig)
			{
				return;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		int len = s[i].size();
		st[s[i][0] - 'a']++;
		ed[s[i][len - 1] - 'a']++;
	}
	sort(s + 1, s + 1 + n);
	int start = 1;
	//如果没有字母句首多出现一次的 那么说明任何字母首尾出现次数都一样
	//那么此时最小链应该从句1开始
	for (int i = 1; i <= n; i++)
	{
		int id = s[i][0] - 'a';
		if (st[id] - ed[id] == 1)
		{
			start = i; //当前字母如果不可能 那么其他同样句首多出现一次的字母也不可能
			break;
		}
	}
	vis[start] = 1;
	dfs(start, 1, s[start] + ".");
	if (trig == 0)
	{
		cout << "***";
	}
	return 0;
}