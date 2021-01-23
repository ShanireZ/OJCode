#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float s, x, v = 7.0, i;
	cin >> s >> x;
	s = s - x;
	
	for(i = 0; s > 0 ; i++)
	{
		v = v * pow(0.98, i);
		s = s - v;
	}
	
	v = v * pow(0.98, i);
	s = x * 2 + s;
	if(s >= v)
	{
		cout << "y";
	}else
	{
		cout << "n";
	}
	return 0;
}
