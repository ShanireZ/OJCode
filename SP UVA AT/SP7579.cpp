#include <algorithm>
#include <iostream>
using namespace std;
int ex[50], lmt, ok, tar;
void dfs(int now, int cnt)
{
	if (cnt > lmt || (now << (lmt - cnt)) < tar)
	{
		return;
	}
	if (now == tar)
	{
		ok = 1;
		return;
	}
	ex[cnt] = now;
	for (int i = 0; i <= cnt && ok == 0; i++)
	{
		dfs(now - ex[i], cnt + 1);
		if (ok)
		{
			return;
		}
		dfs(now + ex[i], cnt + 1);
	}
}
int main()
{
	cin >> tar;
	while (tar)
	{
		lmt = ok = 0;
		while (ok == 0)
		{
			dfs(1, 0);
			lmt++;
		}
		cout << lmt - 1 << endl;
		cin >> tar;
	}
	return 0;
}