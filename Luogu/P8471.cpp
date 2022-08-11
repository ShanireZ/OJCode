#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
vector<int> pa, pb;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		pa.clear(), pb.clear();
		int n, a, e;
		cin >> n >> a >> e >> s;
		n *= 2;
		for (int i = 0; i < n; i++)
		{
			s[i] == 'A' ? pa.push_back(i) : pb.push_back(i);
		}
		int add = a - int(pa.size()); // add为待增加几个A 每增加一个A 可抵消一个错误
		int exc = e - abs(add);		  // exc/2为待交换次数 每交换原来的一对AB 可抵消两个错误
		if (exc < 0 || exc % 2 == 1 || exc / 2 > int(pa.size()) || exc / 2 > int(pb.size()))
		{
			cout << -1 << endl;
			continue;
		}

		while (add > 0)
		{
			pa.push_back(pb[0]);
			pb.erase(pb.begin());
			add--;
		}
		while (add < 0)
		{
			pb.push_back(pa[0]);
			pa.erase(pa.begin());
			add++;
		}

		int p = 0;
		while (exc)
		{
			swap(pa[p], pb[p]);
			exc -= 2, p++;
		}
		p = 0;
		sort(pa.begin(), pa.end());
		for (int i = 0; i < n; i++)
		{
			if (p < int(pa.size()) && pa[p] == i)
			{
				cout << 'A';
				p++;
			}
			else
			{
				cout << 'B';
			}
		}
		cout << endl;
	}
	return 0;
}