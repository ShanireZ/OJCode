#include <iostream>
#include <string>
using namespace std;
string s, ans;
int main()
{
	int t, k;
	cin >> t;
	while (t--)
	{
		ans.clear();
		cin >> s >> k;
		int len = (int)s.size(), pos = 0;
		for (int i = 0; i < len; i++)
		{
			ans += '0';
			if (s[i] != '0' && k)
			{
				for (int j = i; k && j >= pos; j--)
				{
					ans[j] = '9', k--;
				}
				pos = i + 1;
			}
		}
		if (k)
		{
			cout << "-1\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}
	return 0;
}