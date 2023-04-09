#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
	cin >> str;
	// 统计各部分信息
	int pos = str.find('E');
	int ex = stoi(str.substr(pos + 1));
	string f;
	if (str[0] == '-')
	{
		f += '-';
	}
	str = str.substr(1, pos - 1);
	// 处理小数点移动及补0
	pos = str.find('.');
	str.erase(pos, 1);
	pos += ex;
	if (pos > (int)str.size())
	{
		str.append(pos - (int)str.size(), '0');
		pos = str.size();
	}
	else if (pos < 1)
	{
		str.insert(0, 1 - pos, '0');
		pos = 1;
	}
	// 输出
	cout << f << str.substr(0, pos);
	if (pos != (int)str.size())
	{
		cout << '.';
	}
	cout << str.substr(pos) << endl;
	return 0;
}