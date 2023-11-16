#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[2005], n, L;
int main()
{
    cin >> n >> L;
    memset(dp, 0x3f, sizeof(dp)), dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int c, l;
        cin >> c >> l;
        for (int j = L; j >= 0; j--) // 枚举背包剩余部分
        {
            if (j + l > L)
            {
                dp[L] = min(dp[L], dp[j] + c);
            }
            else
            {
                dp[j + l] = min(dp[j + l], dp[j] + c);
            }
        }
    }
    if (dp[L] == 0X3f3f3f3f)
    {
        cout << "no solution" << endl;
    }
    else
    {
        cout << dp[L] << endl;
    }
    return 0;
}