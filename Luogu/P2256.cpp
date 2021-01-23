#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, string> g;
string dfn(string x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		g[name] = name;
	}
	for (int i = 1; i <= m; i++)
	{
		string x, y;
		cin >> x >> y;
		string gx = dfn(x), gy = dfn(y);
		if (gx != gy)
		{
			g[gx] = gy;
		}
	}
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		string x, y;
		cin >> x >> y;
		string gx = dfn(x), gy = dfn(y);
		if (gx == gy)
		{
			cout << "Yes." << endl;
		}
		else
		{
			cout << "No." << endl;
		}
	}
	return 0;
}