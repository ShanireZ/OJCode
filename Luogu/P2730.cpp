#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
map<string, string> mp;
queue<string> q;
string s, ss, ans;
int main()
{
	for (int i = 1; i <= 8; i++)
	{
		int x;
		cin >> x;
		ans += '0' + x;
	}
	reverse(ans.begin() + 4, ans.end());
	mp["12348765"] = "", q.push("12348765");
	while (q.size())
	{
		if (mp.count(ans))
		{
			cout << mp[ans].size() << endl;
			cout << mp[ans] << endl;
			break;
		}
		s = q.front();
		q.pop();
		ss = s.substr(4) + s.substr(0, 4);
		if (mp.count(ss) == 0)
		{
			mp[ss] = mp[s] + 'A', q.push(ss);
		}
		ss = s[3] + s.substr(0, 3) + s[7] + s.substr(4, 3);
		if (mp.count(ss) == 0)
		{
			mp[ss] = mp[s] + 'B', q.push(ss);
		}
		ss = s.substr(0, 1) + s[5] + s[1] + s[3] + s[4] + s[6] + s[2] + s[7];
		if (mp.count(ss) == 0)
		{
			mp[ss] = mp[s] + 'C', q.push(ss);
		}
	}
	return 0;
}
// TAG: 字符串 搜索 哈希 映射