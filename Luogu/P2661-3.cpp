#include <iostream>
#include <algorithm>
using namespace std;
int g[200005];
int cnt;
int minl = 0x3f3f3f3f;
int dfn(int x) //!不進行路徑壓縮
{
	cnt++;
	if (x != g[x])
	{
		return dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 0; //!統計點to到祖先 路線上一共幾個點
		int to;
		cin >> to;
		if (i != dfn(to)) //! 此時i肯定仍自成一組 反向建圖只有i給別人時才會合併i
		{
			g[i] = to;
		}
		else
		{
			minl = min(minl, cnt);
		}
	}
	cout << minl;
	return 0;
}