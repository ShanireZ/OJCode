#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string all, a, b;
	getline(cin, all);
	cin >> a >> b;
	while (all.find(a) != string::npos)
	{
		int p = all.find(a);
		all.replace(p, a.size(), b);
	}
	cout << all;
	return 0;
}