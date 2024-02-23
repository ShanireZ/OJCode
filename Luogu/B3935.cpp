#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int n, m, t, cnt[100005];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> s;
		int pos = 0, now = 0;
		for (char c : s)
		{
			c == '1' ? cnt[pos++] = now, now = 0 : now++;
		}
		cnt[pos] = now;
		if (pos < 2)
		{
			cout << (cnt[0] <= n && cnt[1] <= n ? "Yes\n" : "No\n");
			continue;
		}
		int ok = 1, delta = cnt[1];
		for (int i = 2; i < pos; i++)
		{
			if (delta != cnt[i])
			{
				ok = 0;
				break;
			}
		}
		cout << (ok == 1 && delta <= n && cnt[0] <= delta && cnt[pos] <= delta ? "Yes\n" : "No\n");
	}
	return 0;
}