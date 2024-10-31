#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int dp[105][200005];
vector<int> s[100005];
map<int, int> mp;
int main()
{
	cin.tie(0)->ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k, q, pos = 1;
		cin >> n >> k >> q;
		mp.clear(), mp[1] = 1;
		for (int i = 1; i <= n; i++)
		{
			int l, x;
			cin >> l;
			s[i].clear();
			for (int j = 1; j <= l; j++)
			{
				cin >> x;
				if (mp[x] == 0)
				{
					mp[x] = ++pos;
				}
				s[i].emplace_back(mp[x]);
			}
		}
		for (int i = 0; i <= 100; i++)
		{
			for (int j = 1; j <= pos; j++)
			{
				dp[i][j] = -1; // -1不可达 0可达且不唯一 x可达且唯一
			}
		}
		dp[0][1] = 0; // 第0轮从1开始
		for (int i = 1; i <= 100; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int ed = -1;
				for (int p = 0; p < (int)s[j].size(); p++)
				{
					int num = s[j][p];
					if (p <= ed)
					{
						if (dp[i][num] == -1)
						{
							dp[i][num] = j;
						}
						else if (dp[i][num] != j)
						{
							dp[i][num] = 0;
						}
					}
					if (dp[i - 1][num] != -1 && dp[i - 1][num] != j)
					{
						ed = p + k - 1; // 上一轮出现了当前数,且不是当前人的接龙，那么当前人本轮可以接龙的最远距离
					}
				}
			}
		}
		while (q--)
		{
			int r, c;
			cin >> r >> c;
			c = mp[c];
			if (c == 0 || dp[r][c] == -1)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
	}
	return 0;
}