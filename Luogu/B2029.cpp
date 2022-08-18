#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int h, r;
	cin >> h >> r;
	double s = 3.141592653 * r / 100 * r / 100 * h / 100;
	cout << ceil(0.020 / s) << endl;
	return 0;
}