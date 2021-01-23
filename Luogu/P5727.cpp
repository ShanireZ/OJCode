#include <iostream>
using namespace std;
int all[100005];
int main()
{
	int n;
	cin >> n;
	all[1] = n;
	int i = 2;
	while (n != 1)
	{
		if (n % 2 == 1)
		{
			n = n * 3 + 1;
		}
		else
		{
			n = n / 2;
		}
		all[i] = n;
		i++;
	}
	for (i = i - 1; i >= 1; i--)
	{
		cout << all[i] << " ";
	}
	return 0;
}