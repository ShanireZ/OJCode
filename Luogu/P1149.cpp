/*
	洛谷 P1149
	tag:模拟，函数，搜索
	题意:用指定数目的火柴拼出等式，求一共能拼出多少不同的等式
	思路:声明函数make用以计算当前数字所用的火柴数目
		遍历所有情况，将可以拼出的等式记录
	坑点:每种情况需要调用三次函数，若不使用函数，代码将会比较冗长
		还可使用数组将范围内的所有数字需要的火柴数记录，遍历时可减少重复数字的计算
*/
#include <cstdio>
int amount[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; //所有数字需要火柴数

int make(int i) //计算当前数字需要多少火柴
{
	int count = 0;
	if (i == 0)
	{
		return 6;
	}
	while (i)
	{
		count += amount[i % 10];
		i /= 10;
	}
	return count;
}

int main()
{
	int n, total = 0;
	scanf("%d", &n);
	n -= 4; //除去加号和等号

	for (int i = 0; i < 1000; i++) //元素最高数字不超过1000
	{
		int ai = 0;
		ai = make(i);
		if (ai > n - 4) //每个数字最少2根火柴，剩下不够4根则无法继续完成
		{
			continue;
		}

		for (int j = 0; j < 1000; j++)
		{
			int aj = 0;
			aj = make(j);
			if (aj + ai > n - 2) //最后数字若不够2根则无法完成
			{
				continue;
			}

			int k, ak = 0;
			k = i + j;
			ak = make(k);

			if (ai + aj + ak == n)
			{
				total++;
			}
		}
	}

	printf("%d", total);
	return 0;
}