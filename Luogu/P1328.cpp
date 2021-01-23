#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, nA, nB, i, j, k;
	int scoreA = 0, scoreB = 0;
	cin >> n >> nA >> nB;
	int a[nA], b[nB];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i = 0; i < nA; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < nB; i++)
	{
		cin >> b[i];
	}
	for (i = 0; i < n; i++)
	{
		j = i % nA, k = i % nB;
		if (a[j] == b[k])
		{
			continue;
		}
		if (a[j] == 0 && (b[k] == 2 || b[k] == 3))
		{
			scoreA++;
		}else if(a[j] == 1 && (b[k] == 0 || b[k] == 3))
		{
			scoreA++;
		}else if(a[j] == 2 && (b[k] == 1 || b[k] == 4))
		{
			scoreA++;
		}else if(a[j] == 3 && (b[k] == 2 || b[k] == 4))
		{
			scoreA++;
		}else if(a[j] == 4 && (b[k] == 1 || b[k] == 0))
		{
			scoreA++;
		}else
		{
			scoreB++;
		}
	}
	cout << scoreA << " " << scoreB;
	return 0;
}