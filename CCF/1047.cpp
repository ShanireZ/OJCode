#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[5][5] = {0};
	int i, j, k, max, maxh, maxl, judger;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}
	for(i = 0; i < 5; i++)
	{
		judger = 1;
		max = 0;
		maxh = 0;
		maxl = 0;
		for(j = 0; j < 5; j++)
		{
			if(a[i][j] > max)
			{
				max = a[i][j];
				maxh = i;
				maxl = j;
			}
		}
		for(k = 0; k < 5; k++)
		{
			if(max > a[k][maxl])
			{
				judger = 0;
				break;
			}
		}
		if(judger)
		{
			cout << ++maxh << " " << ++maxl << " " << max;
			return 0;
		}
	}
	cout << "not found";
	return 0;
}
