#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	
	int a, b, length;
	cin >> a >> b;
	length = a + b;
	
	vector <int> x(n);
	vector <int> y(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	
	vector <int> z(n,-1);
	for(int i = 0; i < n; i++)
	{
		if(length >= x[i])
		{
			z[i] = y[i];
		}
	}
	sort(z.begin(),z.end());
	
	int total = 0;
	for(int i = 0; i < z.size(); i++)
	{
		if(z[i] == -1)
		{
			continue;
		}else if(s < z[i])
		{
			break;
		}else
		{
			s -= z[i];
			total++;
		}
	}
	
	cout << total;
	return 0;
}
