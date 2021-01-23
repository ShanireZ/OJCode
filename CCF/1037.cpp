#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b;
	a = a % 10;
	b = b % 4;
	if(b == 0)
	{
		b = 4;
	}	
	c = pow(a,b);
	c = c % 10;
	cout << c;	 
	return 0;
}
