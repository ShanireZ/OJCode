#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int main()
{
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, score;
		cin >> t;
		string name;
		if (t == 1)
		{
			cin >> name >> score;
			if (m[name] == 0)
			{
				tot++;
			}
			m[name] = score;
			cout << "OK" << endl;
		}
		else if (t == 2)
		{
			cin >> name;
			if (m[name] == 0)
			{
				cout << "Not found" << endl;
			}
			else
			{
				cout << m[name] << endl;
			}
		}
		else if (t == 3)
		{
			cin >> name;
			if (m[name] == 0)
			{
				cout << "Not found" << endl;
			}
			else
			{
				tot--;
				m[name] = 0;
				cout << "Deleted successfully" << endl;
			}
		}
		else if (t == 4)
		{
			cout << tot << endl;
		}
	}
	return 0;
}