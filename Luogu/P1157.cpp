#include <iostream>
#include <algorithm>
using namespace std;
int all[25], vis[25], n, r;
void dfs(int step)
{
	if (step > r)
	{
		for (int i = 1; i <= r; i++)
		{
			cout.width(3);
			cout << all[i];
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0 && i > all[step - 1])
		{
			vis[i] = 1;
			all[step] = i;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	cin >> n >> r;
	dfs(1);
	return 0;
}