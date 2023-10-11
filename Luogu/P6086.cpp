#include <algorithm>
#include <iostream>
using namespace std;
int d[5000005], read();
long long a[5000005], ans;
int main()
{
    int n = read(), m = read(), cnt = 0;
    for (int i = 1; i < n - (m == 2); i++)
    {
        a[i] = read(), d[a[i]]++;
    }
    if (m == 1)
    {
        for (int i = 1; i < n; i++)
        {
            int now = i;
            while (d[now] == 0 && now < i + 1 && cnt < n - 2)
            {
                ans ^= a[now] * ++cnt;
                now = a[now], d[now]--;
            }
        }
    }
    else
    {
        a[n - 1] = n;
        for (int i = 1; i < n; i++)
        {
            int now = i;
            while (d[now] == 0 && now < i + 1)
            {
                ans ^= a[++cnt] * now;
                now = a[cnt], d[now]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
int read()
{
    int ans = 0;
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