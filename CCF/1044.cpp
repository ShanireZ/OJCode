#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	int a[n];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	int b[m];
	memset(b, 0, sizeof(b));
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		int j;
		for (j = 1; j < n; j++)
		{
			if (a[j] == a[j - 1])
			{
				continue;
			}
			else if (abs(num - a[j]) >= abs(num - a[j - 1]))
			{
				break;
			}
		}
		b[i] = a[j - 1];
	}
	for (int i = 0; i < m; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}