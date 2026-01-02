#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> to[100005];
long long mn[100005], n;
void dfs(int now, int from)
{
	long long tot = 0;
	for (int nxt : to[now])
	{
		if (nxt != from)
		{
			dfs(nxt, now);
			tot += mn[nxt];
		}
	}
	if (to[now].size())
	{
		mn[now] = min(mn[now], tot);
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int f;
		cin >> f;
		to[f].push_back(i);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> mn[i];
	}
	dfs(1, 0);
	cout << mn[1] << endl;
	return 0;
}