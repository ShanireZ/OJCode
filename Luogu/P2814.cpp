#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, string> g;
string dfn(string name)
{
	if (name != g[name])
	{
		g[name] = dfn(g[name]);
	}
	return g[name];
}
int main()
{
	string str;
	cin >> str;
	string father;
	while (str != "$")
	{
		string name = str.substr(1);
		if (str[0] == '#')
		{
			if (g[name] == "")
			{
				g[name] = name;
			}
			father = dfn(name);
		}
		else if (str[0] == '+')
		{
			g[name] = father;
		}
		else if (str[0] == '?')
		{
			cout << name << " " << dfn(name) << endl;
		}
		cin >> str;
	}
	return 0;
}