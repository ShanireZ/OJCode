#include <algorithm>
#include <iostream>
using namespace std;
int n, ok, a[10];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	do
	{
		for (int i = 1; i <= n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		next_permutation(a + 1, a + 1 + n);
		cin >> ok;
	} while (ok == 0);
	return 0;
}