#include <iostream>
using namespace std;
bool check(int num, int bin)
{
	while (num)
	{
		if (num % bin == 0)
		{
			return false;
		}
		num /= bin;
	}
	return true;
}
int main()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (check(i, 5) && check(i, 7) && check(i, 9))
		{
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}