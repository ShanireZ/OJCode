#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i, j, m = 1;
	cin >> n;
	int a[n][n];
	memset(a,0,sizeof(a));
	a[0][0] = m;
	m++;
	i = 1, j = 0;
	while(m <= n * n)
	{
		while(j < n && i >= 0)
		{
			a[i][j] = m;
			m++;
			i--;
			j++;
		}
		i++;
		if(j >= n)
		{
			i++;
			j--;
		}
		while(j >= 0 && i < n)
		{
			a[i][j] = m;
			m++;
			i++;
			j--;
		}
		j++;
		if(i >= n)
		{
			i--;
			j++;
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
