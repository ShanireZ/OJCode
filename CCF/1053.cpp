/*
	CCF 1053
	tag:��ά����
	����:�Ƚ�����m��n�У���0��1��ɵľ�������ƶ� 
	˼·:���������������ͼ�Σ���ÿ����ͬλ�õĵ���бȽϣ�����¼��ͬ��ͬ�����Ŀ���������ܵ��� 
	�ӵ�:���Ϊ�ٷֱ���ʽ���豣����λС�� 
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
