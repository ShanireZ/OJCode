#include <bits/stdc++.h>
using namespace std;
int b[10000001];	//������������� 
int main()
{
	int n, k, i, j, all, ct = 0, temp;
	cin >> n >> k;
	int a[k];	//����±� 
	memset(a,0,sizeof(a));	
	for(i = 0; i < k; i++)		//����±����a 
	{
		cin >> a[i];
	}
	for(i = 1; i <= n; i++)		//���α�������� 
	{
		all = i;
		temp = i;
		while(temp)
		{
			all += temp % 10;
			temp /= 10;
		}
		if(b[all] == 0)
		{
			b[all] = 1;
			if(all <= n)
			{
				ct++;		//ͳ�Ʒ����������� 
			}
		}
	}
	ct = n - ct;
	cout << ct << endl;	
	int c[ct];		//������飬��С�������������
	memset(c,0,sizeof(c));
	for(i = 0, j = 1; i < ct; j++)		//������������c 
	{
		if(b[j] == 0)
		{
			c[i] = j;
			i++;
		}
	}
	for(i = 0; i < k; i++)		//���ָ���±�������� 
	{
		cout << c[a[i]-1] << " ";
	}	
	return 0;
}
