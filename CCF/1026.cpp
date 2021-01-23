#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float n = 0;
	int max = 0, min = 100, s;
	for(int i = 0; i < 10; i++)
	{
		cin >> s;
		if(s > max)
		{
			max = s;
		}
		if(s < min)
		{
			min = s;
		}
		n += s;
	}
	n = (n - max - min) / 8;
	cout << fixed << setprecision(3) << n;	
	return 0;
}
