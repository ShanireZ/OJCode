#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, i, total = 0, award, maxAward = 0;
	cin >> n;
	string name, maxName;
	int end, mate, num;
	char uni, west;
	for(i = 0; i < n; i++)
	{
		cin >> name >> end >> mate >> uni >> west >> num;
		award = 0;
		if(end > 80 && num >= 1)
		{
			award += 8000;
		}
		if(end > 85 && mate > 80)
		{
			award += 4000;
		}
		if(end > 90)
		{
			award += 2000;
		}
		if(end > 85 && west == 'Y')
		{
			award += 1000;
		}
		if(mate > 80 && uni == 'Y')
		{
			award += 850;
		}
		total += award;
		if(award > maxAward)
		{
			maxName = name;
			maxAward = award;
		}
	}
	cout << maxName << endl << maxAward << endl << total;
	return 0;
}
