#include <iostream>
using namespace std;
int main()
{
	int k, trig = 1;
	cin >> k;
	for (int i = 10000; i <= 30000; i++)
	{
		int n1 = i % 1000;
		int n2 = i / 10 % 1000;
		int n3 = i / 100;
		if (n1 % k == 0 && n2 % k == 0 && n3 % k == 0)
		{
			cout << i << endl;
			trig = 0;
		}
	}
	if (trig)
	{
		cout << "No";
	}
	return 0;
}