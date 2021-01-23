#include <iostream>
#include <string>
using namespace std;
int n1[2005], n2[2005], ans[4005];
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int pos = 0;
	for (int i = str1.size() - 1; i >= 0; i--)
	{
		n1[pos] = str1[i] - '0';
		pos++;
	}
	pos = 0;
	for (int i = str2.size() - 1; i >= 0; i--)
	{
		n2[pos] = str2[i] - '0';
		pos++;
	}
	for (int i = 0; i < str2.size(); i++)
	{
		int p = i;
		for (int j = 0; j < str1.size(); j++)
		{
			ans[p] += n2[i] * n1[j];
			p++;
		}
	}
	for (int i = 0; i <= 4000; i++)
	{
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	int trig = 0;
	for (int i = 4000; i >= 0; i--)
	{
		if (trig == 0 && ans[i] != 0)
		{
			trig = 1;
		}
		if (trig == 1)
		{
			cout << ans[i];
		}
	}
	if (trig == 0)
	{
		cout << 0;
	}
	return 0;
}