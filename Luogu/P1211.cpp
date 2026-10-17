/*
	洛谷 P1211
	tag:貪心，窮舉
	題意:給定n個1~9間的數字，問是否能用這些數字組成牛式
	思路:首先看牛式的要求：
        三位數乘兩位數，部分乘積都是三位數，結果時四位數，且所有數只包含給定的數字
        我們就先把輸入給的n個數字可以組成的三位數和兩位數都窮舉出來，存入陣列中
        然後依次遍歷陣列，看看這兩個數運算出的部分乘積和結果否滿足牛式的要求
	坑點:做題不要想太多，有的題目就是沒啥坑點，不要自己給題目腦補坑點
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