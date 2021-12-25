#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int ans = 0;
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
char s[500005];
vector<long long> all;
int main()
{
    int n = read();
    scanf("%s", s + 1);
    long long cnt = 1;
    char now = s[1];
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == now)
        {
            cnt++;
        }
        else
        {
            all.push_back(cnt);
            now = s[i];
            cnt = 1;
        }
    }
    all.push_back(cnt);
    long long ans = 0;
    for (int i = 0; i < all.size() - 1; i++)
    {
        long long a = all[i], b = all[i + 1], c = 0;
        if (b == 1 && i + 1 != all.size() - 1)
        {
            c = all[i + 2];
            ans += a * (c + 1) - 1;
        }
        else
        {
            ans += (a - 1) + (b - 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}