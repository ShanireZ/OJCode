#include <iostream>
#include <string>
using namespace std;
string ans;
int main()
{
	int k;
	string x;
	cin >> k >> x;
	ans.append("1").append(k, '0');
	if (x.size() > ans.size())
	{
		int pos = (x.size() - 1) - (ans.size() - 1);
		x[pos]++;
		while (x[pos] > '9' && pos > 0)
		{
			x[pos] -= 10;
			pos--;
			x[pos] += 1;
		}
		if (pos == 0 && x[pos] > '9')
		{
			x[pos] -= 10;
			x.insert(0, "1");
		}
		ans = x;
	}
	else if (x.size() == ans.size())
	{
		x[0]++;
		if (x[0] > '9')
		{
			x[0] -= 10;
			x.insert(0, "1");
		}
		ans = x;
	}
	else
	{
		int pos = (ans.size() - 1) - (x.size() - 1);
		ans.replace(pos, x.size(), x);
	}
	cout << ans;
	return 0;
}