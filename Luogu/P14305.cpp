#include <algorithm>
#include <iostream>
using namespace std;
string now, s[10] = {"char", "bool", "int", "longlong", "float", "double"};
int main()
{
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> now;
		int st = now.rfind(",") + 1;
		int vis[6] = {0, 0, 0, 0, 0, 0};
		for (int i = 0; i < 6; i++)
		{
			vis[i] = (now.find(s[i], st) != string::npos);
		}
		int ans = -1;
		for (int i = 5; i >= 0; i--)
		{
			if (vis[i])
			{
				ans = i;
				break;
			}
		}
		if (ans < 2 && now.size() - st > 4)
		{
			ans = 2;
		}
		cout << s[ans] << endl;
	}
	return 0;
}