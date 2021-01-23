/*
	洛谷 P3650
	tag:贪心，穷举
	题意:滑雪场有n座山，为了保证最高的山和最矮的山高度差不大于17，现在要对山的高度进行修改
        修改山高度的费用为 修改值x时费用x^2     求最省钱的修改方案花了多少钱
	思路:将山峰高度从小到大排序，从最矮的山的高度开始，穷举最小高度每上升1时，总费用时多少
        穷举到 最高山的高度-17 结束,因为如果大于这个高度，费用肯定会溢出
	坑点:最小高度不一定是现有山的高度！！！所以要高度穷举要加一，而不是看下一座更高山的高度！！！
        这个坑点价值20分！！！
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void make_cost(int cmp1, int cmp2, int &cost)
{
    int distance = cmp1 - cmp2;
    cost += distance * distance;
}

int main()
{
    int n, cost_min = 9999999;
    cin >> n;
    int hills[n];
    memset(hills, 0, sizeof(hills));
    for (int i = 0; i < n; i++)
    {
        cin >> hills[i];
    }
    sort(hills, hills + n);

    for (int i = hills[0]; i <= hills[n - 1] - 17; i++)
    {
        int cost = 0;
        int min_h = i;
        int max_h = min_h + 17;
        for (int j = 0; j < n; j++)
        {
            if (hills[j] > max_h)
            {
                make_cost(hills[j], max_h, cost);
            }
            else if (hills[j] < min_h)
            {
                make_cost(hills[j], min_h, cost);
            }
        }
        cost_min = min(cost, cost_min);
    }

    cout << cost_min;
    return 0;
}