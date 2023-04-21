#include <algorithm>
#include <iostream>
using namespace std;
char t[20] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
int main()
{
	for (int x = 8; x >= 1; x /= 2)
	{
		for (int i = 1; i <= x; i++)
		{
			int p, q;
			scanf("%d-%d", &p, &q);
			t[i] = (p > q ? t[i * 2 - 1] : t[i * 2]);
		}
	}
	cout << t[1];
	return 0;
}