#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int tota = 0, totb = 0;
	double a = 0, b = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			a++;
			tota += i;
		}
		else
		{
			b++;
			totb += i;
		}
	}
	cout << fixed << setprecision(1) << tota / a << " " << totb / b;
	return 0;
}