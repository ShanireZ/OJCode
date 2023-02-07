#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int s = 0;
    for (int i = 0; i <= 9; i++)
    {
        char ch = getchar();
        if (i != 1) // 小数点忽略
        {
            s = s * 10 + ch - '0';
        }
    }
    if (s == 0)
    {
        printf("%d\n", 4000000 + 60000 + 400 + 1);
        return 0;
    }
    int ans = 0;
    for (int p1 = 0; p1 <= 100; p1++)
    {
        for (int p2 = 0; p2 <= 100; p2++)
        {
            for (int p3 = 0; p3 <= 100; p3++)
            {
                int p = (100 - p1) * (100 - p2) * (100 - p3);
                ans += (100 * p >= s && p != 0 && s % p == 0);
            }
        }
    }
    printf("%d", ans);
    return 0;
}