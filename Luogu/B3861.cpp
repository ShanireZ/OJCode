#include <iostream>
using namespace std;
int sz[1005], fa[1005], n;
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> fa[i];
	}
	for (int i = n; i > 0; i--)
	{
		sz[i] += 1;
		sz[fa[i]] += sz[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << sz[i] << endl;
	}
	return 0;
}