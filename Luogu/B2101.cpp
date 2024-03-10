#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n, m, tot = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if (i == 1 || i == n || j == 1 || j == m)
			{
				tot += x;
			}
		}
	}
	cout << tot << endl;
	return 0;
}