#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	int k = b - a;
	int x = k * (1.0 + sqrt(5)) / 2;
	if (x == a)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	return 0;
}