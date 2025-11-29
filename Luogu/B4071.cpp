#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<long long> cl[1005], kc;
long long n, m, ans = 1e18;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		long long p, c;
		cin >> p >> c;
		cl[p].push_back(c);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(cl[i].begin(), cl[i].end());
	}
	for (int tar = cl[1].size(); tar <= m; tar++)
	{
		long long cost = 0, cnt = cl[1].size();
		for (int j = 2; j <= n; j++)
		{
			long long sz = cl[j].size(), pos = 0;
			while (sz >= tar && pos < (int)cl[j].size())
			{
				cost += cl[j][pos++], sz--, cnt++;
			}
			while (pos < (int)cl[j].size())
			{
				kc.push_back(cl[j][pos++]);
			}
		}
		sort(kc.begin(), kc.end());
		for (int j = 0; j < (int)kc.size() && cnt < tar; j++)
		{
			cost += kc[j], cnt++;
		}
		ans = min(ans, cost), kc.clear();
	}
	cout << ans << endl;
	return 0;
}