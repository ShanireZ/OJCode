#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int x, a, b, c;
	cin >> x >> a >> b >> c;
	if (x >= a)
	{
		cout << "Watermelon" << endl;
	}
	else if (x >= b)
	{
		cout << "Pomegranates" << endl;
	}
	else if (x >= c)
	{
		cout << "Nuts" << endl;
	}
	else
	{
		cout << "Nothing" << endl;
	}
	return 0;
}