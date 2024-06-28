#include <algorithm>
#include <iostream>
using namespace std;
int a[10], n;
void dfs(int now, int tot)
{
	if (tot == n)
	{
		for (int i = 1; i < now - 1; i++)
		{
			cout << a[i] << "+";
		}
		cout << a[now - 1] << '\n';
		return;
	}
	for (int i = a[now - 1]; i < n; i++)
	{
		if (i + tot <= n)
		{
			a[now] = i, dfs(now + 1, tot + i);
		}
	}
}
int main()
{
	cin >> n;
	a[0] = 1, dfs(1, 0);
	return 0;
}