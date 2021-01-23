#include <iostream>
#include <algorithm>
using namespace std;
struct Food
{
    long long a, b, c;
};
Food foods[55];
bool cmp(Food x, Food y) //c/b更小的食材，提前制作能产生更大的美味度
{
    return x.c * y.b < y.c * x.b;
}
long long dp[100005]; //前i种食材，第j秒能到达的美味度
int main()
{
    int t, n;
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> foods[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> foods[i].b;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> foods[i].c;
    }
    sort(foods + 1, foods + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (j >= foods[i].c && foods[i].a - foods[i].b * j >= 0)
            {
                dp[j] = max(dp[j], foods[i].a - foods[i].b * j + dp[j - foods[i].c]);
            }
        }
    }
    long long ans = -1;
    for (int i = 0; i <= t; i++)
    {
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    cout << ans;
    return 0;
}