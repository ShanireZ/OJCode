#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int ans;
int main()
{
	cin >> s >> t;
	for (int i = 0; i <= int(s.size() - t.size()); i++)
	{
		int ok = 1;
		for (int j = 0; j < (int)t.size(); j++)
		{
			if (t[j] == '?')
			{
				continue;
			}
			int x = s[i + j] - t[j];
			if (x != 'a' - 'A' && x != 'A' - 'a')
			{
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	cout << ans << endl;
	return 0;
}