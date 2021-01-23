#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void PreWork(string& str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	str.append(" ");
	str.insert(0, " ");
}

int main()
{
	string s;
	string arti;
	cin >> s;	
	getchar();
	getline(cin, arti);
	PreWork(s);
	PreWork(arti);
	int pos;
	int times = 0, first;
	pos = arti.find(s);
	first = pos;
	while (pos != string::npos)
	{
		times++;
		int newStart = pos;
		pos = arti.find(s, newStart + s.size() - 1);
	}
	if (first != string::npos)
	{
		cout << times << " " << first;
		return 0;
	}
	cout << -1;
	return 0;
}