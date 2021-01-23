#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int countc(int n, int m) //计算组合数Cnm
{
	if (m == 0)
	{
		return 1;
	}
	int ans = 1;
	m = max(m, n - m);
	for (int i = n; i > m; i--)
	{
		ans *= i;
	}
	for (int i = n - m; i > 1; i--)
	{
		ans /= i;
	}
	return ans;
}
int main()
{
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) //不符合升序
	{
		if (s[i] <= s[i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i < s.size(); i++) //计算比s短的有多少个
	{
		ans += countc(26, i);
	}
	char pre = 'a';
	for (int i = 0; i < s.size(); i++) //检查每一位之前有多少个
	{
		for (char j = pre; j <= 'z'; j++)
		{
			if (j < s[i])
			{
				int n = 'z' - j;
				int m = s.size() - (i + 1);
				ans += countc(n, m);
			}
			else
			{
				break;
			}
		}
		pre = s[i] + 1;
	}
	cout << ans + 1;
	return 0;
}