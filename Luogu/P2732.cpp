#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int dp[100005], ys[1005], ans, pos;
struct Sale
{
    int p, key;
};
Sale s[200];
int trans(int x) // 转化6进制
{
    int re = 0;
    for (int i = 0; i <= 5; i++)
    {
        int now = x % 10;
        x /= 10;
        if (now > 5)
        {
            now = 0;
            x += 1;
        }
        re += now * pow(10, i);
    }
    return re;
}
bool check(int x, int y) // 当前x是否可以被y减
{
    for (int i = 0; i <= 5; i++)
    {
        int nx = x % 10, ny = y % 10;
        if (nx < ny)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    memset(dp, 0x3f, sizeof(dp));
    int sp;
    cin >> sp;
    for (int i = 1; i <= sp; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            int c, k;
            cin >> c >> k;
            if (ys[c] == 0)
            {
                ys[c] = ++pos;
            }
            c = ys[c];
            s[i].key += k * pow(10, c - 1);
        }
        cin >> s[i].p;
    }
    int b;
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        int c, k;
        cin >> c >> k >> s[sp + i].p;
        if (ys[c] == 0)
        {
            ys[c] = ++pos;
        }
        c = ys[c];
        ans += k * pow(10, c - 1);
        s[sp + i].key += pow(10, c - 1);
    }
    dp[0] = 0;
    for (int i = 1; i <= b + sp; i++)
    {
        for (int j = s[i].key; j <= ans; j = trans(j + 1))
        {
            if (check(j, s[i].key))
            {
                dp[j] = min(dp[j], dp[j - s[i].key] + s[i].p);
            }
        }
    }
    cout << dp[ans] << endl;
    return 0;
}
