#include <iostream>
using namespace std;
int main()
{
	int max = 0, min = 0, n, number;
	cin >> n;
	cin >> number;
	max = min = number;
	while(n > 1)
	{
		cin >> number;
		if(number > max)
		{
			max = number;
		}else if(number < min)
		{
			min = number;
		}
		n--;
	}
	cout << max - min << endl;
	
	return 0;	
}
