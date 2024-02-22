#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int k, c = 0;
	cin >> k;
	for (int i = 100; i <= 999; i++)
	{
		if (i % k == 0 && i % 100 % k == 0 && i / 10 % k == 0)
		{
			cout << i << endl;
			c++;
		}
	}
	if (c == 0)
	{
		cout << "None!" << endl;
	}
	return 0;
}