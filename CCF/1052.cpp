#include <bits/stdc++.h>
using namespace std;
int b[10000001];	//自我数标记数组 
int main()
{
	int n, k, i, j, all, ct = 0, temp;
	cin >> n >> k;
	int a[k];	//输出下标 
	memset(a,0,sizeof(a));	
	for(i = 0; i < k; i++)		//输出下标存入a 
	{
		cin >> a[i];
	}
	for(i = 1; i <= n; i++)		//依次标记自我数 
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
				ct++;		//统计非自我数个数 
			}
		}
	}
	ct = n - ct;
	cout << ct << endl;	
	int c[ct];		//输出数组，自小至大存入自我数
	memset(c,0,sizeof(c));
	for(i = 0, j = 1; i < ct; j++)		//存入自我数至c 
	{
		if(b[j] == 0)
		{
			c[i] = j;
			i++;
		}
	}
	for(i = 0; i < k; i++)		//输出指定下标的自我数 
	{
		cout << c[a[i]-1] << " ";
	}	
	return 0;
}
