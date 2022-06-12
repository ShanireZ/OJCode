#include <iostream>
#include <stack>
using namespace std;
int lt[1005], up[1005];
long long dp[1005], cnt;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        stack<int> s;
        s.push(0);
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                lt[j] = up[j] = 0;
                continue;
            }
            lt[j] = lt[j - 1] + 1;
            up[j] = up[j] + 1;
            while (up[s.top()] >= up[j])
            {
                s.pop();
            }
            int x = s.top();
            s.push(j);
            if (j - lt[j] >= x)
            {
                dp[j] = up[j] * lt[j];
            }
            else
            {
                dp[j] = dp[x] + up[j] * (j - x);
            }
            cnt += dp[j];
        }
    }
    cout << cnt << endl;
    return 0;
}