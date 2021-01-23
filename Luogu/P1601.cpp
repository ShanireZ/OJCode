#include <iostream>
#include <string>
using namespace std;
int n[105];
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int pos = 0, len = 0;
	for (int i = str1.size() - 1; i >= 0; i--)
	{
		n[pos] = str1[i] - '0';
		pos++;
	}
	pos = 0;
	for (int i = str2.size() - 1; i >= 0; i--)
	{
		n[pos] += str2[i] - '0';
		if (n[pos] >= 10)
		{
			n[pos + 1]++;
			n[pos] -= 10;
		}
		pos++;
	}
	len = max(str1.size() - 1, str2.size() - 1);
	if (n[len + 1] != 0)
	{
		len++;
	}
	for (int i = len; i >= 0; i--)
	{
		cout << n[i];
	}
	return 0;
}