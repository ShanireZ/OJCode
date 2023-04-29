#include <algorithm>
#include <iostream>
using namespace std;
void sp(int now)
{
	if (now == 1)
	{
		cout << "1\n";
		return;
	}
	sp(now / 2);
	cout << "dup\nadd\n";
	if (now % 2 == 1)
	{
		cout << "1\nadd\n";
	}
}
int main()
{
	int n;
	cin >> n;
	sp(n);
	return 0;
}