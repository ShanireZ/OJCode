#include <iostream>
using namespace std;
int mods[100000];
int main()
{
	int n, k;
	cin >> n >> k;
	int tot = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		tot = (tot + tmp) % k;
		mods[tot]++;
	}
	tot = mods[0] % 1234567;
	for (int i = 0; i < k; i++)
	{
		if (mods[i] >= 2)
		{
			tot += mods[i] * (mods[i] - 1) / 2;
			tot %= 1234567;
		}
	}
	cout << tot;
	return 0;
}