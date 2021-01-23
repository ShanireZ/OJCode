/*
	洛谷 P1028
	tag:递推，递归
	题意:一个自然数n不断在其左边加上一个不大于其一半的数，加到不能加为止，求总共能形成多少数
	思路:建立数组存储每个数处理后能生成多少数字
		 从小至大依次递推，省去了使用递归重复模拟的情况
	坑点:若使用递归模拟操作过程，则会TLE超时。因为递归含有大量重复计算 
*/
#include <cstdio>
#include <cstring>
int main()
{
	int n;
	scanf("%d", &n);
	int fun[n + 1];
	memset(fun, 0, sizeof(fun));

	for (int i = 1; i <= n; i++) //模拟初始化
	{
		fun[i] = 1;
	}

	for (int i = 2; i <= n; i++) //依次递推，模拟每个数字的情况
	{
		for (int j = 1; j <= i / 2 && j > 0; j++)
		{
			fun[i] += fun[j];
		}
	}

	printf("%d", fun[n]);
	return 0;
}