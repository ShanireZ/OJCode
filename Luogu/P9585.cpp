#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	if (n <= m / 2)
	{
		cout << 0 << endl;
	}
	else if (m % 2 == 0)
	{
		cout << 4 * (n - m / 2) << endl;
	}
	else
	{
		cout << 4 * (n - m / 2) - 2 << endl;
	}
	return 0;
}