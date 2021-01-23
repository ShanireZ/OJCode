#include <iostream>
using namespace std;

int assign(int m, int n)
{
	if (n <= 1 || m <= 1)
	{
		return 1;
	}
	else if (n > m)
	{
		return assign(m, m);
	}
	else
	{
		return assign(m, n - 1) + assign(m - n, n);
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m >> n;
		cout << assign(m, n) << endl;
	}
	return 0;
}