#include <algorithm>
#include <iostream>
using namespace std;
int bod[1000005], n1, n2;
string s1, s2;
int main()
{
	cin >> s1 >> s2;
	n1 = s1.size(), n2 = s2.size();
	for (int i = 1, j = 0; i < n2; i++)
	{
		while (j != 0 && s2[i] != s2[j])
		{
			j = bod[j - 1];
		}
		bod[i] = (s2[i] == s2[j] ? ++j : 0);
	}
	for (int i = 0, j = 0; i < n1; i++)
	{
		while (j != 0 && s1[i] != s2[j])
		{
			j = bod[j - 1];
		}
		j += (s1[i] == s2[j]);
		if (j == n2)
		{
			cout << i - n2 + 2 << endl;
		}
	}
	for (int i = 0; i < n2; i++)
	{
		cout << bod[i] << " ";
	}
	cout << endl;
	return 0;
}