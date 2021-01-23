#include <iostream>
#include <algorithm>
using namespace std;
int p[105];
int main()
{
	int n, tot = 0, step = 0, ex = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		tot += p[i];
	}
	tot /= n;
	for (int i = 0; i < n; i++)
	{
		if (p[i] + ex != tot)
		{
			ex += p[i] - tot;
			step++;
		}
		else
		{
			ex = 0;
		}
	}
	cout << step;
	return 0;
}