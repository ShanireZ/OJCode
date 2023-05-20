#include <iostream>
#include <string>
using namespace std;
int sz[100005], wd[100005][30];
bool check(int l, int r)
{
	for (int i = 0; i < 26; i++)
	{
		if (wd[r][i] - wd[l - 1][i] == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n, ans = 0x3f3f3f3f, pos = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		sz[i] = sz[i - 1] + (int)s.size();
		for (int j = 0; j < 26; j++)
		{
			wd[i][j] = wd[i - 1][j];
		}
		for (char ch : s)
		{
			wd[i][ch - 'a']++;
		}
		while (check(pos + 1, i))
		{
			pos++;
		}
		if (check(pos, i))
		{
			ans = min(ans, sz[i] - sz[pos - 1]);
		}
	}
	cout << ans << "\n";
	return 0;
}