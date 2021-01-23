#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k[105];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		int tot = 0;
		for (int j = 1; j < i; j++)
		{
			if (k[i] > k[j])
			{
				tot++;
			}
		}
		cout << tot << " ";
	}
	return 0;
}