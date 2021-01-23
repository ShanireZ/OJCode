#include <iostream>
#include <cmath>
using namespace std;
int nums[500005];
int main()
{
	int x, y;
	cin >> x >> y;
	if (y % x != 0)
	{
		cout << 0;
		return 0;
	}
	int m = y / x;
	int tot = 0;
	for (int i = 2; i <= m / 2; i++)
	{
		if (nums[i] == 1)
		{
			continue;
		}
		for (int j = 2; i * j <= m; j++)
		{
			nums[i * j] = 1;
		}
	}
	for (int i = 2; i <= m; i++)
	{
		int trig = 0;
		if (nums[i] == 1)
		{
			continue;
		}
		while (m % i == 0)
		{
			trig = 1;
			m /= i;
		}
		if (trig)
		{
			tot++;
		}
	}
	cout << pow(2, tot);
	return 0;
}