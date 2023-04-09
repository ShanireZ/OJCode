#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string now;
	cin >> now;
	now.insert(0, 4 - (int)now.size(), '0');
	do
	{
		string s1, s2;
		sort(now.begin(), now.end(), greater<char>()), s1 = now;
		sort(now.begin(), now.end(), less<char>()), s2 = now;
		int n1 = stoi(s1), n2 = stoi(s2);
		int ans = n1 - n2;
		now = to_string(ans),
		now.insert(0, 4 - (int)now.size(), '0');
		cout << s1 << " - " << s2 << " = " << now << endl;
	} while (now != "6174" && now != "0000");
	return 0;
}