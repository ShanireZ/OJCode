#include <iostream>
using namespace std;
int main()
{
	int maxD = 0, maxH = 0;
	for (int i = 1; i <= 7; i++)
	{
		int a, b;
		cin >> a >> b;
		a = a + b;
		if (a > 8 && a > maxH)
		{
			maxH = a;
			maxD = i;
		}
	}
	cout << maxD;
	return 0;
}