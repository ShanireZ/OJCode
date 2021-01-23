#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, sizea;
	cin >> n;
	vector <int> a;
	a.push_back(2);
	
	for(int i = 3; i < 20000; i++)
	{
		int judger = true;
		for(int j = 2; j < i; j++)
		{
			if(i % j == 0)
			{
				judger = false;
				break;
			}
		}
		if(judger == true)
		{
			a.push_back(i);
		}		
	}
	sizea = a.size();
	
	for(int i = 0; i < sizea; i++)
	{
		for(int j = 0; j < sizea; j++)
		{
			for(int k = 0; k < sizea; k++)
			{
				if(n == a[i] + a[j] + a[k])
				{
					cout << a[i] << " " << a[j] << " " << a[k];
					return 0;
				}
			}
		}
	}
	return 0;
}
