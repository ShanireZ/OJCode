#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> s;
string gn;
char chs[5] = {'A', 'T', 'C', 'G'};
int main()
{
	int n, k, r;
	cin >> n >> k >> r;
	for (int i = 1; i <= n; i++)
	{
		gn += chs[r % 4];
		r = (r * 6807 + 2831) % 201701;
	}
	for (int i = 0; i + k <= n; i++)
	{
		s.insert(gn.substr(i, k));
	}
	cout << (int)s.size() << "\n";
	return 0;
}