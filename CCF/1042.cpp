#include <iostream>
using namespace std;
int main()
{
	int m = 1, n, a, b, c, i, j, k;
	cin >> n;
	int x[900] = {0};
	int y[15] = {0};
	for(i = 0; i < n * 3; i = i + 3)
	{
		cin >> a >> b >> c;
		x[i] = a + b + c;
		x[i+1] = a;
		x[i+2] = m;
		m++;
	}
	
	for(i = 0; i < n * 3; i = i + 3)
	{
		for(j = 0; j < 15; j = j + 3)
		{
			if(y[j] < x[i] || (y[j] == x[i] && y[j+1] < x[i+1]) || (y[j] == x[i] && y[j+1] == x[i+1] && y[j+2] > x[i+2]))
			{
				for(k = 9; k >= j; k = k - 3)
				{
					y[k+3] = y[k];
					y[k+4] = y[k+1];
					y[k+5] = y[k+2];
				}
				y[j] = x[i];
				y[j+1] = x[i+1];
				y[j+2] = x[i+2];
				break;
			}
		}
	}
	
	for(i = 0; i < 15; i = i + 3)
	{
		cout<< y[i+2] << " " << y[i] << endl;
	}
	return 0;
}
