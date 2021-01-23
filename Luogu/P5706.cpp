#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double t;
	cin >> t;
	int n;
	cin >> n;
	cout << fixed << setprecision(3) << t / n << endl;
	cout << n * 2;
	return 0;
}