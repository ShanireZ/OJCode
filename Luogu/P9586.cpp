#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int c1, c2, c3, d1, d2, d3;
		cin >> c1 >> c2 >> c3 >> d1 >> d2 >> d3;
		if (c1 > d2 || c3 > d1)
		{
			cout << "C\n";
		}
		else if (d1 - c3 > c2 || d3 > c1)
		{
			cout << "D\n";
		}
		else
		{
			cout << "E\n";
		}
	}
	return 0;
}