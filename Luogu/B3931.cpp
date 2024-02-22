#include <algorithm>
#include <iostream>
using namespace std;
int s[5];
int main()
{
	cin >> s[1] >> s[2] >> s[3];
	sort(s + 1, s + 4);
	if (s[3] > s[2] + s[1])
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}