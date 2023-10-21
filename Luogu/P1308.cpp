#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int main()
{
	cin >> s1;
	getline(cin, s2); // 读掉第一行后方的换行符
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
		{
			s1[i] += 32;
		}
	}
	for (int i = 0; i < s2.size(); i++)
	{
		if (s2[i] >= 'A' && s2[i] <= 'Z')
		{
			s2[i] += 32;
		}
	}
	s1.insert(0, " "), s2.insert(0, " "), s1.append(" "), s2.append(" ");
	int pos = s2.find(s1), cnt = 0, first = 1e7;
	while (pos != string::npos)
	{
		cnt++, first = min(first, pos);
		pos = s2.find(s1, pos + 1);
	}
	if (cnt == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << cnt << ' ' << first << endl;
	}
	return 0;
}