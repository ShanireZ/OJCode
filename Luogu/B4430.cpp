#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	long long x1, x2, x3, y1, y2, y3;
	cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
	if (x1 * y1 + x2 * y2 + x3 * y3 == 0)
	{
		cout << "Orthogonal" << endl;
	}
	else
	{
		cout << "Non-Orthogonal" << endl;
	}
	return 0;
}