#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	char now, pre = 'x';
	int cnt = 0;
	while (cin >> now)
	{
		if (now == pre)
		{
			cnt++;
		}
		else
		{
			if (cnt != 0)
			{
				cout << cnt << pre;
			}
			cnt = 1, pre = now;
		}
	}
	cout << cnt << pre;
	return 0;
}