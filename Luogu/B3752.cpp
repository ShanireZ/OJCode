#include <algorithm>
#include <iostream>
using namespace std;
int tn[55], ta[55];
int main()
{
	int t;
	cin >> t;
	tn[1] = 1, ta[2] = 1;
	for (int i = 3; i < 45; i++)
	{
		tn[i] = tn[i - 1] + tn[i - 2];
		ta[i] = ta[i - 1] + ta[i - 2];
	}
	while (t--)
	{
		int x;
		cin >> x;
		for (int i = 2; i < 45; i++)
		{
			int a = (x - tn[i]) / ta[i];
			if (a >= 1 && x == tn[i] + ta[i] * a)
			{
				cout << i << " " << a << "\n";
			}
		}
	}
	return 0;
}