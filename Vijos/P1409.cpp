#include <iostream>
#include <algorithm>
using namespace std;
int v[30005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int w, n, group = 0;
	cin >> w >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	sort(v + 1, v + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (v[i] == 0)
		{
			continue;
		}
		for (int j = i + 1; j <= n; j++)
		{
			if (v[j] == 0)
			{
				continue;
			}
			if (v[i] + v[j] <= w)
			{
				v[j] = 0;
				break;
			}
		}
		v[i] = 0;
		group++;
	}
	cout << group;
	return 0;
}