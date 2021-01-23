/*
	洛谷 P1203
	tag:搜索，字符串，模拟
	题意:一串项链，上面有r,b,w三色的珠子，红蓝相对独立，白色万用
		从任意两个珠子间打断项链，并从两头开始不断收集颜色相同的珠子，直到遇到颜色不同的珠子为止
		问从哪打断项链收集的珠子最多
	思路:模拟从每一个点打断时，收集的珠子的数量，将最大的数输出即可
		其中要解决的问题有：
		珠子坐标问题(珠子坐标是环形的)
		白色万用珠子的问题(会在开头或者中间出现)
		收集量统计和收集量取最大值的问题
	坑点:这算动态规划么？
		主要坑点是会有一串全是相同颜色的珠子！尤其是全白的比较难处理！
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string necklace = "";

int reset(int num)
{
	if (num > n - 1)
	{
		num -= n;
	}
	else if (num < 0)
	{
		num += n;
	}
	return num;
}

void check_start(int &total, int &start, int end, int add)
{
	while (necklace[reset(start)] == 'w')
	{
		start += add;
		total++;
		if (reset(start) == reset(end))
		{
			cout << n;
			exit(0);
		}
	}
}

void count_jewel(int &total, int start, int range_i, int add)
{
	for (int i = 0; i < range_i; i++)
	{
		if (necklace[start] == necklace[reset(start + i * add)] || necklace[reset(start + i * add)] == 'w')
		{
			total++;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	cin >> n >> necklace;
	int max_jewel = 0;
	for (int i = 0; i < n; i++)
	{
		int total = 0;
		int pos_start = i;
		int pos_end = i - 1;
		check_start(total, pos_start, pos_end, 1);
		count_jewel(total, pos_start, n, 1);
		int pos_cost = total;
		pos_start += (total - 1);
		check_start(total, pos_end, pos_start, -1);
		count_jewel(total, pos_end, n - pos_cost, -1);
		max_jewel = max(max_jewel, total);
	}
	cout << max_jewel;
	return 0;
}