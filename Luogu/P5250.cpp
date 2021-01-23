#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t, len;
		cin >> t >> len;
		if (t == 1)
		{
			if (s.count(len))
			{
				cout << "Already Exist" << endl;
			}
			s.insert(len);
		}
		else
		{
			if (s.empty())
			{
				cout << "Empty" << endl;
			}
			else
			{
				set<int>::iterator itr = s.lower_bound(len);
				set<int>::iterator itl = itr;
				if (itr != s.begin())
				{
					itl--;
				}
				if (itr == s.end() || len - *itl <= *itr - len)
				{
					cout << *itl << endl;
					s.erase(*itl);
				}
				else
				{
					cout << *itr << endl;
					s.erase(*itr);
				}
			}
		}
	}
	return 0;
}