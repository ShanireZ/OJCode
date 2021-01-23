#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i, j = 0, k, male = 0, female = 0;
	string m;
	cin >> n;
	double a[2][n], temp;
	memset(a,0,sizeof(a));
	for(i = 0; i < n; i++)
	{
		cin >> m;
		if(m == "male")
		{
			cin >> a[0][j];
			male++;
		}else
		{
			cin >> a[1][j];
			female++;
		}
		j++;
	}
	for(k = 0; k < 2; k++)
	{
		for(i = 0; i < n; i = j)
		{
			j = i + 1;
			while(a[k][i-1] > a[k][i] && i >= 1)
			{
				temp = a[k][i-1];
				a[k][i-1] = a[k][i];
				a[k][i] = temp;
				i--;
			}
		}
	}
	for(i = n - male; i < n; i++)
	{
		cout << fixed << setprecision(2) << a[0][i] << " ";
	}
	for(i = n - 1; i >= n - female; i--)
	{
		cout << a[1][i] << " ";
	}
	return 0;
}
