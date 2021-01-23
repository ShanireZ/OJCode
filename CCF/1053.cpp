/*
	CCF 1053
	tag:二维数组
	题意:比较两个m行n列，由0和1组成的矩阵的相似度 
	思路:建立数组存入两个图形，对每个相同位置的点进行比较，并记录相同或不同点的数目，最后除以总点数 
	坑点:输出为百分比形式且需保留两位小数 
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, i, j;
	double k = 0;
	cin >> m >> n;
	int a[m][n], b[m][n];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> b[i][j];
			if(a[i][j] != b[i][j])
			{
				k++;
			}
		}
	}
	cout << fixed << setprecision(2) << 100-k*100/(n*m);
	return 0;
}
