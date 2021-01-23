#include <iostream>
#include <cmath>
using namespace std;
int a[40005];
int main()
{
	char ch, pre = '0';
	int tot = 0, pos = 1, n = 0;
	while (cin >> ch)
	{
		tot = tot + 1;
		if (ch == pre)
		{
			n = n + 1;
		}
		else
		{
			a[pos] = n;
			pos++;
			n = 1;
			pre = ch;
		}
	}
	a[pos] = n;
	cout << sqrt(tot) << " ";
	for (int i = 1; i <= pos; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}