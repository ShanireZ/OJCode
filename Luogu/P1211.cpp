/*
	洛谷 P1211
	tag:贪心，穷举
	题意:给定n个1~9间的数字，问是否能用这些数字组成牛式
	思路:首先看牛式的要求：
        三位数乘两位数，部分乘积都是三位数，结果时四位数，且所有数只包含给定的数字
        我们就先把输入给的n个数字可以组成的三位数和两位数都穷举出来，存入数组中
        然后依次遍历数组，看看这两个数运算出的部分乘积和结果否满足牛式的要求
	坑点:做题不要想太多，有的题目就是没啥坑点，不要自己给题目脑补坑点
*/

#include <iostream>
#include <cstring>
using namespace std;
int n;
int nums[9];
int nums_2[81];
int nums_3[729];

void make_nums()
{
	int p2 = 0, p3 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			nums_2[p2++] = nums[i] + 10 * nums[j];
			for (int k = 0; k < n; k++)
			{
				nums_3[p3++] = nums[i] + 10 * nums[j] + 100 * nums[k];
			}
		}
	}
}

bool check(int num)
{
	while (num != 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == (num % 10))
			{
				break;
			}
			if (i == n - 1)
			{
				return 0;
			}
		}
		num /= 10;
	}
	return 1;
}

int main()
{
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	make_nums();
	for (int n1 = 0; n1 < n * n * n; n1++)
	{
		for (int n2 = 0; n2 < n * n; n2++)
		{
			int num1 = nums_3[n1] * (nums_2[n2] % 10);
			int num2 = nums_3[n1] * (nums_2[n2] / 10);
			int num3 = nums_3[n1] * nums_2[n2];
			if (num1 > 999 || num2 > 999 || num3 > 9999 || num3 < 1000)
			{
				continue;
			}
			if (check(num1) && check(num2) && check(num3))
			{
				total++;
			}
		}
	}
	cout << total;
	return 0;
}