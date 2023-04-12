#include <iostream>
#include <string>
using namespace std;
string a, b;
int main()
{
	cin >> a >> b;
	int pa = a.find('.'), pb = b.find('.');
	if (a.substr(pa) == b.substr(pb))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}