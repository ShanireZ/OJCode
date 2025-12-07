#include <algorithm>
#include <iostream>
using namespace std;
int a[100005][3], n, c0, c1;
int main()
{
	cin >> n;
	for (int k = 0; k < 3; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][k];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i][0] + a[i][1] + a[i][2] == 300)
		{
			c0++;
		}
		else
		{
			sort(a[i], a[i] + 3);
			if (a[i][1] >= 95 && a[i][2] >= 95 && a[i][0] >= 90)
			{
				c1++;
			}
		}
	}
	cout << c0 << " " << c1 << endl;
	return 0;
}