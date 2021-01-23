#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, x, y, z, i, j, tempa, tempb, tempc, trig;
	cin >> a >> b >> c;
	for(i = 2; i <= 16; i++)
	{
		trig = 1;
		z = 0;
		x = 0;
		y = 0;
		tempc = c;
		tempa = a;
		tempb = b;
		for(j = 0; (tempc > 0 || tempa >0 || tempb > 0) && trig; j++)
		{
			if(tempc % 10 >= i || tempa % 10 >= i || tempb % 10 >= i)
			{
				trig = 0;
			}
			z += tempc % 10 * pow(i,j);
			x += tempa % 10 * pow(i,j);
			y += tempb % 10 * pow(i,j);
			tempc /= 10;
			tempa /= 10;
			tempb /= 10;
		}
		if(trig == 0)
		{
			continue;
		}else if(z == x * y)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0; 
}
