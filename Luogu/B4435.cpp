#include <algorithm>
#include <iostream>
using namespace std;
string s[105], pre;
int n, ans, sz[105];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		sz[i] = s[i].size();
	}
	for (int i = 1; i <= n; i++)
	{
		int ok = 0;
		for (int j = 1; j <= n && ok == 0; j++)
		{
			if (i == j)
			{
				continue;
			}
			pre.clear();
			for (int len = 1; len <= min(sz[i] - 1, sz[j]) && ok == 0; len++)
			{
				pre += s[j][len - 1];
				for (int k = 1; k <= n && ok == 0; k++)
				{
					if (i == k || len + sz[k] < sz[i])
					{
						continue;
					}
					ok = (pre + s[k].substr(sz[k] - sz[i] + len) == s[i]);
				}
			}
		}
		ans += ok;
	}
	cout << ans << endl;
	return 0;
}