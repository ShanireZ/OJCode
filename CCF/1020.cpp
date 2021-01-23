#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b;
	cin >> a;
	b = a;
	int count = 0;
	while(a > 0)
	{
		count++;
		a /= 10;
	}
	cout << count << endl;
	for(; count > 0; count--)
	{
		a = b / pow(10, count -1);
		cout << a << endl;
		b = b - a * pow(10, count -1);
	}
	return 0;
}
