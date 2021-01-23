#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, i, j, errorh = 0, errorl = 0;
	cin >> n;
	int h[n], l[n];
	memset(h,0,sizeof(h));
	memset(l,0,sizeof(l));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> m;
			h[i] += m;
			l[j] += m;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(h[i] % 2 != 0 && errorh == 0)
		{
			errorh = i + 1;
		}else if(h[i] % 2 != 0 && errorh != 0)
		{
			cout << "Corrupt";
			return 0;
		}
		if(l[i] % 2 != 0 && errorl == 0)
		{
			errorl = i + 1;
		}else if(l[i] % 2 != 0 && errorl != 0)
		{
			cout << "Corrupt";
			return 0;
		}
	}
	if(errorh == 0 && errorl == 0)
	{
		cout << "OK";
	}else if(errorh != 0 && errorl != 0)
	{
		cout << errorh << " " << errorl;
	}else
	{
		cout << "Corrupt";
	}
	return 0;
}
