#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	int r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
	{
		swap(a, b);
	}
	if (a > c)
	{
		swap(a, c);
	}
	if (b > c)
	{
		swap(b, c);
	}
	int g = gcd(a, c); //__gcd(x,y) 非标准库函数
	cout << a / g << "/" << c / g;
	return 0;
}