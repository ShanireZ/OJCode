#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int number, n = 0, i, end;
	cin >> number;
	end = sqrt(number);
	
	for(i = 1; i <= end; i++)
	{
		if(number % i == 0)
		{
			n += 2;
		}
	}
	if(end * end == number)
	{
		n--;
	}

	cout << n;
	
	return 0;	
}
