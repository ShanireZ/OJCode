#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	if (t == 1)
	{
		cout << "I love Luogu!";
	}
	else if (t == 2)
	{
		cout << 2 + 4 << " " << 10 - 2 - 4;
	}
	else if (t == 3)
	{
		cout << 14 / 4 << endl
			 << 14 / 4 * 4 << endl
			 << 14 - 14 / 4 * 4;
	}
	else if (t == 4)
	{
		cout << setprecision(6) << 500.0 / 3;
	}
	else if (t == 5)
	{
		cout << (260 + 220) / (12 + 20);
	}
	else if (t == 6)
	{
		cout << sqrt(6 * 6 + 9 * 9);
	}
	else if (t == 7)
	{
		cout << 100 + 10 << endl
			 << 100 + 10 - 20 << endl
			 << 0;
	}
	else if (t == 8)
	{
		cout << 2 * 3.141593 * 5 << endl
			 << 3.141593 * 5 * 5 << endl
			 << 3.141593 * 5 * 5 * 5 * 4 / 3;
	}
	else if (t == 9)
	{
		cout << 22;
	}
	else if (t == 10)
	{
		cout << 9;
	}
	else if (t == 11)
	{
		cout << 100.0 / 3;
	}
	else if (t == 12)
	{
		cout << 13 << endl
			 << 'R';
	}
	else if (t == 13)
	{
		cout << int(pow(3.141593 * 4 / 3 * (4 * 4 * 4 + 10 * 10 * 10), 1.0 / 3));
	}
	else if (t == 14)
	{
		double a = (120 - sqrt(120 * 120 - 4 * 1 * 3500)) / 2;
		cout << round(a);
	}
	return 0;
}