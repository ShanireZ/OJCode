/*
	洛谷 P1208
	tag:貪心，二維陣列排序，揹包
	題意:marry乳業公司每日從m家牛奶供應商處收購指定數量的牛奶
        這些供應商的每日提供量和單價不一
        求花費最少的購買方法
	思路:首先處理所有輸入資料，建立二維陣列儲存供應商們的牛奶單價和日最大供應量
		將該二維陣列以牛奶單價為比較值，從小到大進行排序
        依次購買每個供應商的牛奶，直至買到足夠的牛奶
	坑點:二維陣列sort排序，揹包問題解決方法
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