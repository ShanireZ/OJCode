#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string a;
	cin >> a;
	if(isdigit(a[0]))
	{
		cout << "no";
		return 0;
	}
	int i = 0;
	while(i < a.size())
	{
		if(isalnum(a[i]) || a[i] == '_')
		{
		}else
		{
			cout << "no";
			return 0;
		}
		i++;
	}
	cout << "yes";
	return 0;
}
