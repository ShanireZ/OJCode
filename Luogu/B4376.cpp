#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min({a, b, c, d / 4}) << endl;
	return 0;
}