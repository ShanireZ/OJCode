#include <iostream>
using namespace std;
int main()
{
	int x, n, tot = 0;
	cin >> x >> n;
	while (n > 0)
	{
		if (x <= 5)
		{
			tot += 250;
		}
		x++;
		n--;
		if (x > 7)
		{
			x = 1;
		}
	}
	cout << tot;
	return 0;
}