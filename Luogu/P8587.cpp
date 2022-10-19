#include <iostream>
using namespace std;
int cnt[3005], tot[6005];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int h;
		cin >> h;
		cnt[h]++;
	}
	for(int i = 1; i <= 3000; i++)
	{
		for(int j = i; j <= 3000; j++)
		{
			if(i == j)
			{
				tot[i + j] += cnt[i] / 2;
			}
			else
			{
				tot[i + j] += min(cnt[i], cnt[j]);
			}
		}
	}
	int maxp = tot[2], fa = 1;
	for(int i = 3; i <= 6000; i++)
	{
		if(tot[i] > maxp)
		{
			maxp = tot[i], fa = 1;
		}
		else if(tot[i] == maxp)
		{
			fa++;
		}
	}
	cout << maxp << " " << fa << endl;
	return 0;
} 