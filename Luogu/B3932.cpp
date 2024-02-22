#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	double a, b, c, d, e, x, y;
	cin >> a >> b >> c >> d >> e >> x >> y;
	double t1 = a * x + b * y, t2 = c * y, t3 = d * y + e;
	if (t1 >= t2 && t1 >= t3)
	{
		cout << fixed << setprecision(2) << "1 " << t1 << endl;
	}
	else if (t2 >= t1 && t2 >= t3)
	{
		cout << fixed << setprecision(2) << "2 " << t2 << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << "3 " << t3 << endl;
	}
	return 0;
}