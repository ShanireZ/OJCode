#include <algorithm>
#include <iostream>
using namespace std;
string s;
int d[1000005], n;
int main()
{
	cin >> n >> s;
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = d[j - 1];
		}
		d[i] = (s[i] == s[j] ? ++j : 0);
	}
	cout << n - d[n - 1] << endl;
	return 0;
}