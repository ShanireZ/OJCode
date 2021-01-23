#include <iostream>
#include <algorithm>
using namespace std;
int a[15];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	prev_permutation(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}