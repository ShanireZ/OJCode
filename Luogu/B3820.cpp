#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
char ch;
long long n, t, tot, k, pos, cpos, flag, a[1000005], read();
int main()
{
    t = read();
    while (t--)
    {
        n = read(), ch = getchar();
        tot = flag = pos = cpos = 0, k = 0;
        while (ch < '0' || ch > '9')
        {
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            ++cpos;
            if (cpos <= 17)
            {
                k = k * 10 + ch - '0';
            }
            ch = getchar();
        }
        for (int i = 1; i <= n; i++)
        {
            long long x = read();
            if (pos == 0 || x % 2 == 0 || x % 3 == 0 || x % 7 == 0 || x % 11 == 0)
            {
                a[++pos] = x;
            }
            tot += x;
        }
        if (tot >= k)
        {
            flag = 1;
        }
        for (int i = 1; i <= pos && flag == 0; i++)
        {
            for (int j = i + 1; j <= pos && flag == 0; j++)
            {
                if (a[i] * a[j] % 154 == 0 || a[i] * a[j] % 147 == 0)
                {
                    flag = 1;
                }
            }
        }
        printf("%s\n", flag == 1 ? "Yes" : "No");
    }
    return 0;
}
long long read()
{
    long long ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
// TAG: 数学 因数