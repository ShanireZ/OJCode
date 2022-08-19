#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << setw(8) << a << " ";
	cout << setw(8) << b << " ";
	cout << setw(8) << c << " ";
	return 0;
}