#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
map<string, set<int>> mp;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++)
		{
			string word;
			cin >> word;
			mp[word].insert(i);
		}
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		string word;
		cin >> word;
		for (set<int>::iterator i = mp[word].begin(); i != mp[word].end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl;
	}
	return 0;
}