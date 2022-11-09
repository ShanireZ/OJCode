#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
int cnt[25];
// 二进制是20位内(1,048,575以内)的质数个数 cnt[5]二进制恰好5位的质数个数
vector<int> prim;
int vis[1100000];
void cntW(int x)
{
    int ans = 0;
    while (x / 2 != 0)
    {
        ans++;
        x /= 2;
    }
    cnt[ans]++;
}
void OLS()
{
    for (int i = 2; i <= 1100000; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            prim.push_back(i);
            cntW(i);
        }
        for (int j = 0; j < prim.size() && i * prim[j] <= 1100000; j++)
        {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    OLS();
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        int ans = 0;
        for (int j = 0; j <= 20 && x; j++)
        {
            if (x % 2 == 1)
            {
                ans += cnt[j];
            }
            x /= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}