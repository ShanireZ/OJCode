#include <iostream>
#include <algorithm>
using namespace std;
int g[200005];
int cnt;
int minl = 0x3f3f3f3f;
int dfn(int x) //!不进行路径压缩
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
		cnt = 0; //!统计点to到祖先 路线上一共几个点
		int to;
		cin >> to;
		if (i != dfn(to)) //! 此时i肯定仍自成一组 反向建图只有i给别人时才会合并i
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