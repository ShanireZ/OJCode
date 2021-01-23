#include <iostream>
using namespace std;
int main()
{
	int m, n, temp;
	cin >> m >> n;
	while(m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	if(n != 1)
	{
		cout << "No";
	}else
	{
		cout << "Yes";
	}
	return 0;
}
