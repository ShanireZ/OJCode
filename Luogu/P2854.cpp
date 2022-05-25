#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Edge
{
    int st, ed, v, c;
    bool operator<(const Edge oth) const
    {
        return ed < oth.ed;
    }
};
Edge es[10005];
int dp[1005][1005]; // dp[位置][价格]
int main()
{
    int l, n, b;
    cin >> l >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> es[i].st >> es[i].ed >> es[i].v >> es[i].c;
        es[i].ed += es[i].st;
    }
    sort(es + 1, es + 1 + n);
    int pos = 1;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= b; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= l; i++) // 枚举结束位置
    {
        while (es[pos].ed == i && pos <= n) // 枚举每个该位置结束的线段
        {
            for (int j = b; j >= es[i].c; j--) // 枚举价格
            {
                if (dp[es[pos].st][j - es[pos].c] != -1)
                {
                    dp[i][j] = max(dp[i][j], dp[es[pos].st][j - es[pos].c] + es[pos].v);
                }
            }
            pos++;
        }
    }
    cout << dp[l][b] << endl;
    return 0;
}