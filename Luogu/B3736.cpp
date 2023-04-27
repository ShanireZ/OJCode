#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	cout << __gcd(__gcd(x, y), z) << "\n";
	return 0;
}