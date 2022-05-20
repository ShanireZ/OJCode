#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[120005], cnt[10];
int main()
{
    for (int id = 1; true; id++)
    {
        int tot = 0;
        for (int i = 1; i <= 6; i++)
        {
            scanf("%d", cnt + i);
            tot += cnt[i] * i;
        }
        if (tot == 0)
        {
            break;
        }
        printf("Collection #%d:\n", id);
        if (tot % 2 != 0)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= 6; i++)
        {
            if (cnt[i] == 0)
            {
                continue;
            }
            int base = 1;
            while (cnt[i] >= base)
            {
                for (int j = tot / 2; j >= base * i; j--)
                {
                    dp[j] = max(dp[j], dp[j - base * i]);
                }
                cnt[i] -= base;
                base *= 2;
            }
            for (int j = tot / 2; j >= cnt[i] * i; j--)
            {
                dp[j] = max(dp[j], dp[j - cnt[i] * i]);
            }
        }
        if (dp[tot / 2])
        {
            printf("Can be divided.\n\n");
        }
        else
        {
            printf("Can't be divided.\n\n");
        }
    }
    return 0;
}