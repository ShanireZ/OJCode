#include <iostream>
using namespace std;
int l[155][155], up[155][155];
char mp[155][155];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'B')
            {
                continue;
            }
            l[i][j] = l[i][j - 1] + 1;
            up[i][j] = up[i - 1][j] + 1;
            int now = 300;
            for (int k = 0; k < up[i][j]; k++) // 可用单调栈优化 找到第一个小于该位置宽度的行号
            {
                now = min(now, l[i - k][j]);
                cnt += now;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}