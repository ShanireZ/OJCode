/*
	��� P1056 CCF 1055
	tag:����,��������,��������
	����:��D�԰�˵����ͬѧ��������ȣ���֤����������ָܷ��������ܶ�İ�˵��ͬѧ
	˼·:�����������ÿ��/���Լ������ȿɸ���������ͬѧ����/�б�ţ��ٶ�������Ӵ�С������
		 ����󣬶���Ҫ�������/�к��ٴ�С�����������
	�ӵ�:��ά�������н��� 
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, k, l, d;
	cin >> m >> n >> k >> l >> d;
	int a[m][2], b[n][2], c[2];		//cΪ�������� 
	int r[k], t[l];		//r t����� 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(r,0,sizeof(r));
	memset(t,0,sizeof(t));
	int x, y, p, q, i, j, temp;	
	for(i = 0; i < d; i++)		//����&�������� 
	{
		cin >> x >> y >> p >> q;
		if(x == p)
		{
			if(y > q)
			{
				b[q][1]++;
				b[q][0] = q;
			}else
			{
				b[y][1]++;
				b[y][0] = y;
			}
		}else if(y == q)
		{
			if(x > p)
			{
				a[p][1]++;
				a[p][0] = p;
			}else
			{
				a[x][1]++;
				a[x][0] = x;
			}
		}
	}
	for(i = 0; i < m; i = j)		//�Ӵ���С������������� 
	{
		j = i + 1;
		while(i >= 1)
		{
			if(a[i-1][1] < a[i][1])
			{
				memcpy(c,a[i-1],sizeof(c));
				memcpy(a[i-1],a[i],sizeof(c));
				memcpy(a[i],c,sizeof(c));
				i--;
			}else
			{
				break;
			}
		}
	}
	for(i = 0; i < n; i = j)
	{
		j = i + 1;
		while(i >= 1)
		{
			if(b[i-1][1] < b[i][1])
			{
				memcpy(c,b[i-1],sizeof(c));
				memcpy(b[i-1],b[i],sizeof(c));
				memcpy(b[i],c,sizeof(c));
				i--;
			}else
			{
				break;
			}
		}
	}
	for(i = 0; i < k; i++)		//�����Ž��д����������� 
	{
		r[i] = a[i][0];
	}
	for(i = 0; i < l; i++)
	{
		t[i] = b[i][0];
	}
	for(i = 0; i < k; i = j)		//����������� 
	{
		j = i + 1;
		while(i >= 1)
		{
			if(r[i-1] > r[i])
			{
				temp = r[i-1];
				r[i-1] = r[i];
				r[i] = temp;
				i--;
			}else
			{
				break;
			}
		}
	}
	for(i = 0; i < l; i = j)
	{
		j = i + 1;
		while(i >= 1)
		{
			if(t[i-1] > t[i])
			{
				temp = t[i-1];
				t[i-1] = t[i];
				t[i] = temp;
				i--;
			}else
			{
				break;
			}
		}
	}
	for(i = 0; i < k; i++)		//��� 
	{
		cout << r[i] << " ";
	}
	cout << endl;
	for(i = 0; i < l; i++)
	{
		cout << t[i] << " ";
	}
	return 0;
}
