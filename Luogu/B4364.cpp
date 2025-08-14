#include <algorithm>
#include <iostream>
using namespace std;
string str;
int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	__int128 res = min((__int128)b, (__int128)n * a);
	if (res == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	while (res)
	{
		str += res % 10 + '0';
		res /= 10;
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
	return 0;
}