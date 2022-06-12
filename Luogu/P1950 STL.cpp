#include <iostream>
#include <stack>
using namespace std;
int lt[1005][1005], up[1005][1005];
long long dp[1005][1005], cnt;
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
                continue;
            }
            lt[i][j] = lt[i][j - 1] + 1;
            up[i][j] = up[i - 1][j] + 1;
            while (up[i][s.top()] >= up[i][j])
            {
                s.pop();
            }
            int x = s.top();
            s.push(j);
            if (j - lt[i][j] >= x)
            {
                dp[i][j] += up[i][j] * lt[i][j];
            }
            else
            {
                dp[i][j] += dp[i][x] + up[i][j] * (j - x);
            }
            cnt += dp[i][j];
        }
    }
    cout << cnt << endl;
    return 0;
}