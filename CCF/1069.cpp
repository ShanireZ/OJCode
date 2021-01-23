#include <iostream>
#include <cmath>
using namespace std;
int times;

void fact(int remain, int pre) //Factorization
{
	if (remain == 1)
	{
		times++;
	}
	else
	{
		for (int i = pre; i <= remain; i++)
		{
			if (remain % i == 0)
			{
				fact(remain / i, i);
			}
		}
		times++;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		times = 0;
		fact(a, 2);
		cout << times << endl;
	}
	return 0;
}