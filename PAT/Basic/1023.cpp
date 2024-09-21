#include <algorithm>
#include <iostream>
using namespace std;
string ans;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		int t;
		cin >> t;
		for (int j = 1; j <= t; j++)
		{
			ans += char('0' + i);
		}
	}
	for (int i = 0; i < (int)ans.size(); i++)
	{
		if (ans[i] != '0')
		{
			swap(ans[0], ans[i]);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}