#include <iostream>
#include <set>
using namespace std;
set<string> s;
string x;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		s.emplace(x);
	}
	cout << 52 - s.size() << endl;
	return 0;
}