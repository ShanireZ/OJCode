#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int zj(int n1, int n2, int n3)
{
	if (n1 > n2 && n1 > n3)
	{
		return n1;
	}
	else if (n2 > n1 && n2 > n3)
	{
		return n2;
	}
	else
	{
		return n3;
	}
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << fixed << setprecision(3) << 1.0 * zj(a, b, c) / (zj(a + b, b, c) * zj(a, b, b + c));
	return 0;
}