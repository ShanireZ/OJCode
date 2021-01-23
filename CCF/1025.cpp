#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int day, goldTotal = 0, silverTotal = 0, bronzeTotal = 0;
	int i, gold, silver, bronze;
	cin >> day;
	for(i = 1; i <= day; i++)
	{
		cin >> gold >> silver >> bronze;
		goldTotal += gold;
		silverTotal += silver;
		bronzeTotal += bronze;
	}
	i = goldTotal + silverTotal + bronzeTotal;
	cout << goldTotal << " " << silverTotal << " " << bronzeTotal << " " << i;
	return 0;	
}
