#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int grt = 0, num = 0, len = s.size();
		for (char ch : s)
		{
			if (ch >= 'A' && ch <= 'Z')
			{
				grt = 1;
			}
			else if (isdigit(ch))
			{
				num = 1;
			}
		}
		cout << ((grt && num && len >= 8) ? "Y" : "N") << endl;
	}
	return 0;
}