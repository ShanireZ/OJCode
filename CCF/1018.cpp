#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float x;
	cin >> x;
	x = ceil(x * 10);
	int a = 0;
	if(x == 5)
	{
		cout << 3;
	}else
	{
		x -= 5;
		a = x / 2 + 3;
		cout << a;
	}
	return 0;
}
