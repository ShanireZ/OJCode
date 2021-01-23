#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int num = 1;
	for (int hang = 1; hang <= n; hang++)
	{
		for (int lie = 1; lie <= n + 1 - hang; lie++)
		{
			if (num < 10)
			{
				cout << 0;
			}
			cout << num;
			num++;
		}
		cout << endl;
	}
	return 0;
}