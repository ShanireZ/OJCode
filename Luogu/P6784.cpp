#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	if (a < b)
	{
		swap(a, b);
	}
	long long d = a - b;
	b += min(d, c);
	c -= min(d, c);
	a += c / 2, b += c / 2;
	for (int i = 1; i <= 1e7; i++)
	{
		a -= i, b -= i;
		if (a < 0 || b < 0)
		{
			d = i;
			break;
		}
	}
	cout << d - 1;
	return 0;
}