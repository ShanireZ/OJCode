#include <cstdio>
#include <algorithm>
using namespace std;
int nxt[10000010], pos;
bool check[10000010];
int read()
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
bool h7(int x)
{
    bool trig = false;
    while (x)
    {
        if (x % 10 == 7)
        {
            trig = true;
            break;
        }
        x /= 10;
    }
    return trig;
}
int main()
{
    for (int i = 1; i <= 10000005; i++)
    {
        if (check[i])
        {
            continue;
        }
        if (h7(i))
        {
            for (int j = i; j <= 10000005; j += i)
            {
                check[j] = 1;
            }
            continue;
        }
        fill(nxt + pos, nxt + i, i);
        pos = i;
    }
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int now = read();
        if (check[now])
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", nxt[now]);
        }
    }
    return 0;
}