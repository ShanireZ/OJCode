#include <iostream>
using namespace std;
int main()
{
	int a[16], i, j, m = 0, n = 0;
	for(i = 0; i < 16; i++)
	{
		cin >> a[i];
	}
	i = 0, j = 3;
	for(; i < 16;)
	{
		m += a[i];
		n += a[j];
		i += 5;
		j += 3;
	}
	cout << m << " " << n;
}
