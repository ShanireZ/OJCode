#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int t, f, h;
    bool operator<(const Node oth) const
    {
        return t < oth.t;
    }
};
Node ns[105];
int dp[105]; // 每个高度的最大生命
int main()
{
    int d, g;
    cin >> d >> g;
    for (int i = 1; i <= g; i++)
    {
        cin >> ns[i].t >> ns[i].f >> ns[i].h;
    }
    sort(ns + 1, ns + 1 + g);
    dp[0] = 10;
    for (int i = 1; i <= g; i++)
    {
        for (int j = d; j >= 0; j--)
        {
            if (dp[j] < ns[i].t) // 生命不够撑到第i个垃圾
            {
                continue;
            }
            if (j + ns[i].h >= d)
            {
                cout << ns[i].t << endl;
                return 0;
            }
            dp[j + ns[i].h] = max(dp[j + ns[i].h], dp[j]); // 不吃第i堆垃圾，高度增加生命不变
            dp[j] = max(dp[j], dp[j] + ns[i].f);           // 吃了第i堆垃圾，高度不变生命增加
        }
    }
    cout << dp[0] << endl;
    return 0;
}