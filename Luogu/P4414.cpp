#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
	{
		swap(a, b);
	}
	if (a > c)
	{
		swap(a, c);
	}
	if (b > c)
	{
		swap(b, c);
	}
	for (int i = 1; i <= 3; i++)
	{
		char t;
		cin >> t;
		if (t == 'A')
		{
			cout << a << " ";
		}
		else if (t == 'B')
		{
			cout << b << " ";
		}
		else
		{
			cout << c << " ";
		}
	}
	return 0;
}