#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, i, j;
	cin >> n >> m;
	int a[m][n];
	memset(a,0,sizeof(a));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> a[j][n-1-i];
		}
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
