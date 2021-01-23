#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i, m, j = 0;
	cin >> n;
	int a[1001];
	memset(a,0,sizeof(a));
	for(i = 0; i < n; i++)
	{
		cin >> m;
		if(a[m] == 0)
		{
			a[m] = 1;
			j++;
		}
	}
	cout << j << endl;
	for(i = 0; i < 1001; i++)
	{
		if(a[i] == 1)
		{
			cout << i << " ";
		}
	}
	return 0;
}
