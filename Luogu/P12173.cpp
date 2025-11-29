#include <algorithm>
#include <iostream>
using namespace std;
string s, gs[6] = {"lqb", "lbq", "qlb", "qbl", "blq", "bql"};
int ans, pos = 2;
int main()
{
	cin >> s;
	while (pos < (int)s.size())
	{
		for (int i = 0; i < 6; i++)
		{
			if (gs[i] == s.substr(pos - 2, 3))
			{
				ans++, pos += 2;
				break;
			}
		}
		pos++;
	}
	cout << ans << endl;
	return 0;
}