#include <algorithm>
#include <iostream>
using namespace std;
__int128 c[55][55], ans;
void opt(__int128 x)
{
    if (x > 9)
    {
        opt(x / 10);
    }
    cout << (int)(x % 10);
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < 50; i++)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i < 50; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            ans += c[n + i - 1][n - 1] * c[n + j - 1][n - 1];
        }
    }
    opt(ans);
    return 0;
}
// TAG: 排列组合 数学 插空法 DP 动态规划 枚举