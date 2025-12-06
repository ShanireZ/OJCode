#include <algorithm>
#include <iostream>
using namespace std;
int n, ex, p1 = 1, p2 = 2, a[600005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	while (ex < n && p1 <= n && p2 <= n)
	{
		if (a[p1 + ex] == a[p2 + ex])
		{
			ex++;
		}
		else
		{
			a[p1 + ex] > a[p2 + ex] ? p1 = p1 + ex + 1 : p2 = p2 + ex + 1;
			ex = 0;
			if (p1 == p2)
			{
				p2++;
			}
		}
	}
	for (int i = min(p1, p2), ex = 0; ex < n; ex++)
	{
		cout << a[i + ex] << " ";
	}
	cout << endl;
	return 0;
}