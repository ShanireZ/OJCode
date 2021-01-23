#include <iostream>
using namespace std;
int main()
{
	int a[105] = {0};
	for (int i = 1; i <= 100; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			break;
		}
	}
	for (int i = 100; i >= 1; i--)
	{
		if (a[i] != 0)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}