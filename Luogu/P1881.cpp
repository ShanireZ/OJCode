#include <algorithm>
#include <iostream>
using namespace std;
int pos[105];
int main()
{
    int n, len, ans = 1;
    cin >> n >> len;
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
        pos[i] *= 2;
    }
    sort(pos + 1, pos + n + 1);
    for (int i = 2; i < n; i++)
    {
        int p = pos[i], sz = min(i - 1, n - i), ok = 1;
        for (int j = 1; j <= sz && ok; j++)
        {
            if (p - pos[i - j] != pos[i + j] - p)
            {
                ok = 0;
            }
        }
        ans += ok;
        p = (pos[i] + pos[i + 1]) / 2, sz = min(i, n - i), ok = 1;
        for (int j = 0; j < sz && ok; j++)
        {
            if (p - pos[i - j] != pos[i + 1 + j] - p)
            {
                ok = 0;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 枚举 小数优化整数运算