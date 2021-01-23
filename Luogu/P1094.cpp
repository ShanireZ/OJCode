#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int w, n, count = 0, pos = 0;
	cin >> w >> n;
	int gift[n];
	memset(gift, 0, sizeof(gift));
	for (int i = 0; i < n; i++)
	{
		cin >> gift[i];
	}
	sort(gift, gift + n);
	for (int i = n - 1; i >= pos; i--)
	{
		if (i != pos && (gift[i] + gift[pos] <= w))
		{
			pos++;
		}
		count++;
	}
	cout << count;
	return 0;
}