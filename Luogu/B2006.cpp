#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	int x, a, y, b;
	cin >> x >> a >> y >> b;
	double ans = 1.0 * (x * a - y * b) / (a - b);
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}