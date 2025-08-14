#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a > 0)
	{
		cout << (b > 0 ? "NorthEast" : "NorthWest") << endl;
	}
	else
	{
		cout << (b > 0 ? "SouthEast" : "SouthWest") << endl;
	}
	return 0;
}