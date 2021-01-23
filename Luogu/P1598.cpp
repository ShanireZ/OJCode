#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt[30];
int main()
{
	string str;
	int maxt = 0;
	for (int i = 1; i <= 4; i++) //输入并统计每个字母出现次数
	{
		getline(cin, str);
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] >= 'A' && str[j] <= 'Z')
			{
				int id = str[j] - 'A';
				cnt[id]++;
				maxt = max(maxt, cnt[id]);
			}
		}
	}
	for (int i = maxt; i >= 1; i--) //根据出现次数输出符号
	{
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j] >= i)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 26; i++) //输出对应字母
	{
		char ch = 'A' + i;
		cout << ch << " ";
	}
	return 0;
}