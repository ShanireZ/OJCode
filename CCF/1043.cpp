#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
int main()
{
	int r, n, i, j;
	cin >> r >> n;
	int a[r];
	memset(a,0,sizeof(a));
	int l, t, w, h;
	for(i = 0; i < n; i++)	//�������� 
	{
		cin >> l >> t >> w >> h;
		for(j = 0; j < w; j++)
		{
			a[l+j] += h;
		}
	}
	n = 0;
	for(i = 0; i < r; i++)	//ͳ������� 
	{
		n += a[i]; 
	}
	w = 0;		//����� 
	h = 0;		//����� 
	for(i = 0; i < r; i++)
	{
		w += a[i];
		h = n - w;
		if(w >= h)
		{
			break;
		}
	}	
	i++;	//�Ҳ�����ͼ������ 
	for(; i < r; i++)
	{
		if(a[i] != 0)
		{
			break;
		}
	}
	cout << i;	
	return 0;
}
