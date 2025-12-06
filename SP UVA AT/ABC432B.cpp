#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string x;
	cin >> x;
	vector<int> v;
	int c0 = 0;
	for (char ch : x)
	{
		if (ch == '0')
		{
			c0++;
		}
		else
		{
			v.push_back(ch - '0');
		}
	}
	sort(v.begin(), v.end());
	cout << v[0];
	for (int i = 1; i <= c0; i++)
	{
		cout << 0;
	}
	for (int i = 1; i < (int)v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}