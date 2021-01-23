#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
int maxn[100005][20];
//! RMQ问题 随机多次询问区间最值
//! 常用方法及时间复杂度
//! 1.遍历 预处理n q次询问qn
//! 2.线段树 预处理n q次询问qlogn
//! 3.ST表(动态规划思想) 预处理nlogn q次询问q
//! 4.先规约成LCA 再规约成约束RMQ 预处理n q次询问q
//! 首先根据原数列，建立笛卡尔树，从而将问题在线性时间内规约为LCA问题。
//! LCA问题可以在线性时间内规约为约束RMQ
//! 也就是数列中任意两个相邻的数的差都是+1或-1的RMQ问题
//! 而约束RMQ有预处理O(n)单次询问O(1)的在线解法
inline int read() //? 快读 能快一倍 哈压一
{
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch))
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x * f;
}
int main()
{
	int n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		maxn[i][0] = read(); //!从i开始长度为2^0的区间 最大值为自身
	}
	//! 从a开始长度为2^x的区间最大值 =
	//! max(从a开始长度为2^x-1的区间最大值,从a+2^x-1开始长度为2^x-1的区间最大值)
	for (int i = 1; i <= log2(n); i++) //!最大区间长度为2的几次方 倍增思想
	{
		for (int j = 1; j <= n; j++) //!如果区间超出剪枝
		{
			if (j + pow(2, i) - 1 > n)
			{
				break;
			}
			int half = j + pow(2, i - 1);
			maxn[j][i] = max(maxn[j][i - 1], maxn[half][i - 1]);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int l = read(), r = read();
		int t = log2(r - l + 1);	  //!覆盖l,r中点 需要的区间得多长
		int half = r - pow(2, t) + 1; //!第二个区间的起点 = 终点 - 2^t + 1
		printf("%d\n", max(maxn[l][t], maxn[half][t]));
	}
	return 0;
}