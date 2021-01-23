#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
int main()
{
	double a,b,c,d,e;
	cin >> a >> b >> c >> d;
	e = abs(a-c) + abs(b-d);
	cout << fixed << setprecision(3) << e;
	return 0;
}
