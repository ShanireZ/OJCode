#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, i, j;
	double wait = 0;
	cin >> n;
	int time[n][2];
	int tmp[2];
	memset(time, 0, sizeof(time));
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < n; i++)
	{
		cin >> time[i][0];
		time[i][1] = i;
	}
	for (i = 0; i < n; i = j)
	{
		j = i + 1;
		while (i >= 1)
		{
			if (time[i - 1][0] > time[i][0])
			{
				memcpy(tmp, time[i - 1], sizeof(tmp));
				memcpy(time[i - 1], time[i], sizeof(tmp));
				memcpy(time[i], tmp, sizeof(tmp));
				i--;
			}
			else
			{
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout << time[i][1] + 1 << " ";
		wait += time[i][0] * (n - 1 - i);
	}
	cout << endl;
	wait /= n;
	cout << fixed << setprecision(2) << wait;
	return 0;
}