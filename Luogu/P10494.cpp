#include <algorithm>
#include <iostream>
using namespace std;
int ex[50], lmt, ok, tar;
void dfs(int now, int step)
{
	if (now == tar)
	{
		ok = 1;
		return;
	}
	if (step >= lmt || (now << (lmt - step)) < tar)
	{
		return;
	}
	ex[step] = now;
	for (int i = step; i >= 0 && ok == 0; i--)
	{
		dfs(now - ex[i], step + 1);
		if (ok)
		{
			return;
		}
		dfs(now + ex[i], step + 1);
	}
}
int main()
{
	cin >> tar;
	while (ok == 0)
	{
		dfs(1, 0);
		lmt++;
	}
	cout << lmt - 1 << endl;
	return 0;
}