/*
	洛谷 P1208
	tag:贪心，二维数组排序，背包
	题意:marry乳业公司每日从m家牛奶供应商处收购指定数量的牛奶
        这些供应商的每日提供量和单价不一
        求花费最少的购买方法
	思路:首先处理所有输入数据，建立二维数组存储供应商们的牛奶单价和日最大供应量
		将该二维数组以牛奶单价为比较值，从小到大进行排序
        依次购买每个供应商的牛奶，直至买到足够的牛奶
	坑点:二维数组sort排序，背包问题解决方法
*/

#include <bits/stdc++.h>
using namespace std;

bool CmpFun(vector<int> a, vector<int> b)
{
    return (a[0] < b[0]);
}

int main()
{
    int total, m, cost = 0;
    cin >> total >> m;
    vector<vector<int>> milk(m);
    for (int i = 0; i < m; i++)
    {
        milk[i].resize(2);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> milk[i][0] >> milk[i][1];
    }
    sort(milk.begin(), milk.end(), CmpFun);
    for (int i = 0; i < m; i++)
    {
        if (total <= milk[i][1])
        {
            cost += milk[i][0] * total;
            break;
        }
        total -= milk[i][1];
        cost += milk[i][0] * milk[i][1];
    }
    cout << cost;
    return 0;
}