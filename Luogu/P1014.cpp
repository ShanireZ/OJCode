#include <iostream>
using namespace std;
int main()
{
	int n, i, a, b;
	cin >> n;
	for (i = 1; n - i > 0; i++)
	{
		n = n - i;
	}
	if (i % 2 == 0)
	{
		a = n;
		b = i - n + 1;
	}
	else
	{
		a = i - n + 1;
		b = n;
	}
	cout << a << "/" << b;
	return 0;
}
