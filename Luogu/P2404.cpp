/*
	洛谷 P2404 CCF 1077
	tag:递归，DFS，枚举
	题意:输入一个自然数n，将n拆分为若干个小于n的自然数的和
		将拆分后的式子列出，按字典序将式子排序
	思路:按字典序排列，所以后数要保证不小于该数，所以后数的最小值就是前数
		递归的递减元素为当次分解中待分解的数，每一层分解过后，待分解的数都会减小
		当待分解的数为0时，说明分解完毕；未分解完毕时，递归下一次分解
		分解完毕后，就需要将本次分解好的数一一输出，同时退回到上层，进行下一个枚举
	坑点:比较直白的DFS回溯题目
		最大的坑点在于不用输出不分解的式子，所以需要加入判断
*/

#include <iostream>
using namespace std;
int tree[21] = {1}; //存储每个分解出的数，最小为1
int n;

void output_tree(int pos) //打印本次结果
{
	for (int i = 1; i < pos; i++)
	{
		cout << tree[i] << '+';
	}
	cout << tree[pos] << endl;
}

void make_tree(int pos, int remain) //分解层数，待分解的数
{
	for (int i = tree[pos - 1]; i <= remain; i++) //不小于上个数，且最大就是待分解的数
	{
		if (i == n) //一步也没分解不用打印
		{
			break;
		}
		tree[pos] = i;		 //存入本次分解出的数
		if (remain - i == 0) //如果分解完毕
		{
			output_tree(pos);
		}
		else
		{
			make_tree(pos + 1, remain - i); //继续下一次分解
		}
	}
}

int main()
{
	cin >> n;
	int m = n;
	make_tree(1, m); //当前是第一层，分解的数为m
	return 0;
}