#include <algorithm>
#include <iostream>
using namespace std;
struct Good
{
    int a, b, c;
    bool operator<(const Good oth) const
    {
        return c < oth.c;
    }
};
Good gs[1005];
int dp[1005];
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gs[i].a >> gs[i].b >> gs[i].c;
    }
    sort(gs + 1, gs + 1 + n);
    int st = 1, ed = 1;
    while (st <= n)
    {
        for (int i = st; i <= n + 1; i++)
        {
            if (gs[i].c != gs[st].c)
            {
                ed = i;
                break;
            }
        }
        for (int i = m; i >= 1; i--)
        {
            int v = dp[i];
            for (int j = st; j < ed; j++)
            {
                if (i >= gs[j].a)
                {
                    v = max(v, dp[i - gs[j].a] + gs[j].b);
                }
            }
            dp[i] = v;
        }
        st = ed;
    }
    cout << dp[m] << endl;
    return 0;
}