#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int pos[10005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i] >> pos[i];
	}
	sort(pos, pos + n);
	int avg = pos[n / 2];
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		tot += abs(avg - pos[i]);
	}
	cout << tot;
	return 0;
}