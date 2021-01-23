#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a = a * 60 + b;
	c = c * 60 + d;
	b = (c - a) / 60;
	d = (c - a) % 60;
	cout << b << " " << d;
	return 0;
}