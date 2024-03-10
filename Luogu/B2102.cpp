#include <algorithm>
#include <iostream>
using namespace std;
int a[10][10], maxh[10];
int main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> a[i][j];
			if (a[i][maxh[i]] < a[i][j])
			{
				maxh[i] = j;
			}
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		int l = maxh[i], t = 1;
		for (int j = 1; j <= 5; j++)
		{
			if (a[i][l] > a[j][l])
			{
				t = 0;
				break;
			}
		}
		if (t)
		{
			cout << i << " " << l << " " << a[i][l] << endl;
			return 0;
		}
	}
	cout << "not found" << endl;
	return 0;
}