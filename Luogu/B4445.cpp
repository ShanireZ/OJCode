#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	double v, g, m, n;
	cin >> v >> g >> m >> n;
	double s1 = 0.5 * v;
	double s2 = (g < 300 ? m : n);
	cout << fixed << setprecision(1) << min(s1, s2) << endl;
	return 0;
}