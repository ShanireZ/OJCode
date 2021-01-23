#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n, age, i;
	float total = 0.0;
	cin >> n;
	
	for(i=n; i>0; i--)
	{
		cin >> age;
		total += age;
	}
	
	total = total / n;
	cout << fixed << setprecision(2) << total;
	return 0;	
}
