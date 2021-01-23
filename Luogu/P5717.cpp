#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(c < a)
	{
		swap(c, a);
	}
	if(c < b)
	{
		swap(c, b);
	}
	
	if(a + b <= c)
	{
		cout << "Not triangle" << endl;
		return 0; 
	}
	//余弦定理
	if(a * a + b * b == c * c)
	{
		cout << "Right triangle" << endl; 
	}
	else if(a * a + b * b > c * c)
	{
		cout << "Acute triangle" << endl;
	}
	else
	{
		cout << "Obtuse triangle" << endl;
	}
	
	if(a == b)
	{
		cout << "Isosceles triangle" << endl;
	}
	if(a == b && b == c)
	{
		cout << "Equilateral triangle" << endl; 
	}
	return 0;
}