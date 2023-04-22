#include <iostream>
using namespace std;
int main()
{
	int x, y, t;
	cin >> x >> y >> t;
	cout << int(x * t * y / (y - x)) << "\n";
	return 0;
}