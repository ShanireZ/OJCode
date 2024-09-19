#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0))
		{
			if (abs(a) <= abs(b)) // 让a绝对值更大
			{
				swap(a, b);
			}
			while (b != 0 && a / b != 0)
			{
				a = a % b;
				swap(a, b);
			}
		}
		cout << min(min(abs(a), abs(b)), min(abs(a + b), abs(a - b))) << '\n';
	}
	return 0;
}