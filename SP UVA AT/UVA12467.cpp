#include <algorithm>
#include <iostream>
using namespace std;
int n, T, len, p, d[1000005];
string s;
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s;
		len = 0, n = s.size();
		for (int i = 1, j = 0; i < n; i++)
		{
			while (j > 0 && s[i] != s[j])
			{
				j = d[j - 1];
			}
			j += (s[i] == s[j]);
			d[i] = j;
		}
		for (int i = n - 1, j = 0; i >= 0; i--)
		{
			while (j > 0 && s[i] != s[j])
			{
				j = d[j - 1];
			}
			j += (s[i] == s[j]);
			if (j > len)
			{
				len = j, p = i;
			}
		}
		cout << s.substr(p, len) << endl;
	}
	return 0;
}