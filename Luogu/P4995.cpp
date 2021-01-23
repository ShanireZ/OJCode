#include <iostream>
#include <algorithm>
using namespace std;
long long h[305];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	int st = 0, ed = n;
	long long c = 0;
	while (st < ed)
	{
		c += (h[st] - h[ed]) * (h[st] - h[ed]);
		st++;
		c += (h[st] - h[ed]) * (h[st] - h[ed]);
		ed--;
	}
	cout << c;
	return 0;
}