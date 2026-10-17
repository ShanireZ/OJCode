/*
	洛谷 P3650
	tag:貪心，窮舉
	題意:滑雪場有n座山，為了保證最高的山和最矮的山高度差不大於17，現在要對山的高度進行修改
        修改山高度的費用為 修改值x時費用x^2     求最省錢的修改方案花了多少錢
	思路:將山峰高度從小到大排序，從最矮的山的高度開始，窮舉最小高度每上升1時，總費用時多少
        窮舉到 最高山的高度-17 結束,因為如果大於這個高度，費用肯定會溢出
	坑點:最小高度不一定是現有山的高度！！！所以要高度窮舉要加一，而不是看下一座更高山的高度！！！
        這個坑點價值20分！！！
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