#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r, c, n, m;
	cin >> r >> c >> n;
	int i, j, k;
	char a[r][c], b[r][c];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
	for(k = 0; k < n; k++)
	{
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
			{
				if(i-1 >= 0)	//ио 
				{
					m = abs(a[i][j] - a[i-1][j]);
					if(m == 1)
					{
						if(b[i][j] == 'R' || b[i][j] == 'S' || b[i][j] == 0)
						{
							b[i][j] = 'R';
						}
					}else if(m == 2)
					{
						if(b[i][j] == 'R' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'P';
						}
					}else if(m == 3)
					{
						if(b[i][j] == 'S' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'S';
						}
					}else
					{
						m = abs(b[i][j] - a[i][j]);
						if(m == 1) 
						{
							b[i][j] = 'R';
						}else if(m == 2)
						{
							b[i][j] = 'P';
						}else if(m == 3)
						{
							b[i][j] = 'S';
						}else
						{
							b[i][j] = a[i][j];
						}
					}
				}
				if(i+1 < r)		//об 
				{
					m = abs(a[i][j] - a[i+1][j]);
					if(m == 1)
					{
						if(b[i][j] == 'R' || b[i][j] == 'S' || b[i][j] == 0)
						{
							b[i][j] = 'R';
						}
					}else if(m == 2)
					{
						if(b[i][j] == 'R' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'P';
						}
					}else if(m == 3)
					{
						if(b[i][j] == 'S' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'S';
						}
					}else
					{
						m = abs(b[i][j] - a[i][j]);
						if(m == 1) 
						{
							b[i][j] = 'R';
						}else if(m == 2)
						{
							b[i][j] = 'P';
						}else if(m == 3)
						{
							b[i][j] = 'S';
						}else
						{
							b[i][j] = a[i][j];
						}
					}
				}
				if(j-1 >= 0)	//вС
				{
					m = abs(a[i][j] - a[i][j-1]);
					if(m == 1)
					{
						if(b[i][j] == 'R' || b[i][j] == 'S' || b[i][j] == 0)
						{
							b[i][j] = 'R';
						}
					}else if(m == 2)
					{
						if(b[i][j] == 'R' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'P';
						}
					}else if(m == 3)
					{
						if(b[i][j] == 'S' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'S';
						}
					}else
					{
						m = abs(b[i][j] - a[i][j]);
						if(m == 1) 
						{
							b[i][j] = 'R';
						}else if(m == 2)
						{
							b[i][j] = 'P';
						}else if(m == 3)
						{
							b[i][j] = 'S';
						}else
						{
							b[i][j] = a[i][j];
						}
					}
				}
				if(j+1 < c)		//ср
				{
					m = abs(a[i][j] - a[i][j+1]);
					if(m == 1)
					{
						if(b[i][j] == 'R' || b[i][j] == 'S' || b[i][j] == 0)
						{
							b[i][j] = 'R';
						}
					}else if(m == 2)
					{
						if(b[i][j] == 'R' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'P';
						}
					}else if(m == 3)
					{
						if(b[i][j] == 'S' || b[i][j] == 'P' || b[i][j] == 0)
						{
							b[i][j] = 'S';
						}
					}else
					{
						m = abs(b[i][j] - a[i][j]);
						if(m == 1) 
						{
							b[i][j] = 'R';
						}else if(m == 2)
						{
							b[i][j] = 'P';
						}else if(m == 3)
						{
							b[i][j] = 'S';
						}else
						{
							b[i][j] = a[i][j];
						}
					}
				}
			}
		}
		for(i = 0; i < r; i++)
		{
			for(j = 0; j < c; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
	
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
