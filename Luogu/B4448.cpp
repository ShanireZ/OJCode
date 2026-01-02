#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int h, w, x, cnt = 0;
	cin >> h >> w >> x;
	for (int r = 1; r <= h; r++)
	{
		for (int c = 1; c <= w; c++)
		{
			cnt += (r * r + c * c <= (x + r - c) * (x + r - c));
		}
	}
	cout << cnt << endl;
	return 0;
}