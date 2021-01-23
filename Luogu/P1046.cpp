#include <iostream>
using namespace std;
int main()
{
	int a[15] = {0};
	for (int i = 1; i <= 10; i++)
	{
		cin >> a[i];
	}
	int h, tot = 0;
	cin >> h;
	h = h + 30;
	for (int i = 1; i <= 10; i++)
	{
		if (h >= a[i])
		{
			tot++;
		}
	}
	cout << tot;
	return 0;
}