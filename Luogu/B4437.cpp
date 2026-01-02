#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
	cout << min(x / 3, y / 2) << endl;
	return 0;
}