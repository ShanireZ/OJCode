#include <iostream>
using namespace std;
int main()
{
	int number, total = 0;
	cin >> number;
	
	while(number > 0)
	{
		total += number % 10;
		number /= 10;
	}
	cout << total;
	
	return 0;	
}
