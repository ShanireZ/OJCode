#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string initials[50] = {"b", "p", "m", "f", "d", "t", "n", "l", "g", "k", "h", "j", "q", "x", "zh", "ch", "sh", "r", "z", "c", "s", "y", "w"};
string finals[50] = {"a", "o", "e", "i", "u", "ai", "ei", "ui", "ao", "ou", "iu", "ie", "ue", "er", "an", "en", "in", "un", "ang", "eng", "ing", "ong"};
bool isPinyin(string word)
{
	for (string s1 : initials)
	{
		if (word.substr(0, s1.size()) == s1)
		{
			string suf = word.substr(s1.size());
			for (string s2 : finals)
			{
				if (suf == s2)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, cnt = 0;
		cin >> n;
		string word;
		for (int i = 1; i <= n; i++)
		{
			cin >> word;
			cnt += isPinyin(word);
		}
		cout << (cnt >= 0.5 * n ? "Pinyin\n" : "English\n");
	}
	return 0;
}