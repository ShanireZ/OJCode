#include <algorithm>
#include <iostream>
using namespace std;
int a[15], rec[60000][15], n, pos;
void dfs(int now)
{
	if (now > 10)
	{
		int tot = 0;
		for (int i = 1; i <= 10; i++)
		{
			tot += a[i];
		}
		if (tot == n)
		{
			pos++;
			for (int i = 1; i <= 10; i++)
			{
				rec[pos][i] = a[i];
			}
		}
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		a[now] = i;
		dfs(now + 1);
	}
}
int main()
{
	cin >> n;
	dfs(1);
	cout << pos << endl;
	for (int i = 1; i <= pos; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout << rec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}