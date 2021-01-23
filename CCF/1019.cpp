#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float a, b;
	cin >> a;
	if(a >= 0 && a < 5)
	{
		b = a + 2.5;
	}else if(a >= 5 && a < 10)
	{
		b = 2 - 1.5 * (a - 3) * (a - 3);
	}else
	{
		b = a / 2 - 1.5;
	}
	cout << fixed << setprecision(3) << b;
	return 0;
}
