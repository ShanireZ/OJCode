#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int p[105] = {0};
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		total += p[i];
	}
	total /= n;
	int times = 0;
	for (int i = 1; i < n; i++)
	{
		if (p[i] < total)
		{
			p[i + 1] -= (total - p[i]);
			times++;
		}
		else if (p[i] > total)
		{
			p[i + 1] += (p[i] - total);
			times++;
		}
	}
	cout << times;
	return 0;
}