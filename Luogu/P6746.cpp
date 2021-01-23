#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == b)
	{
		if (a == 0)
		{
			cout << 0;
		}
		else
		{
			cout << min(c, d * 2);
		}
	}
	else
	{
		if (a == 0 || b == 0)
		{
			cout << d;
		}
		else if (d <= c)
		{
			cout << d * 2;
		}
		else
		{
			cout << c + d;
		}
	}
	return 0;
}