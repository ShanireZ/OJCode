#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int read();
int all[1000005], pos[500005];
char op[1000005];
bool func(int n, int st)
{
    int cnt = 1, now = all[st];
    int l = 1, r = n * 2;                       //前半段取值范围
    int nl = pos[now] - st, nr = pos[now] - st; //后半段已取范围
    if (st == 1)
    {
        op[1] = 'L', l++;
    }
    else
    {
        op[1] = 'R', r--;
    }
    op[n * 2] = 'L';
    while (cnt < n) //凑够一半
    {
        if (l < nl) //左侧取数
        {
            now = all[l];
            if ((nr + 1 <= r && all[nr + 1] == now) ||
                (nl - 1 > l && all[nl - 1] == now))
            {
                op[++cnt] = 'L';
                if (nl - 1 > l && all[nl - 1] == now) //对称侧在左边取
                {
                    op[2 * n + 1 - cnt] = 'L', nl--;
                }
                else //对称侧在右边取
                {
                    op[2 * n + 1 - cnt] = 'R', nr++;
                }
                l++;
                continue;
            }
        }
        if (r > nr) //右侧取数
        {
            now = all[r];
            if ((nr + 1 < r && all[nr + 1] == now) ||
                (nl - 1 >= l && all[nl - 1] == now))
            {
                op[++cnt] = 'R';
                if (nl - 1 >= l && all[nl - 1] == now)
                {
                    op[2 * n + 1 - cnt] = 'L', nl--;
                }
                else
                {
                    op[2 * n + 1 - cnt] = 'R', nr++;
                }
                r--;
                continue;
            }
        }
        break;
    }
    if (cnt == n)
    {
        for (int i = 1; i <= n * 2; i++)
        {
            printf("%c", op[i]);
        }
        printf("\n");
        return true;
    }
    return false;
}
int main()
{
    int t = read();
    for (int i = 1; i <= t; i++)
    {
        int n = read();
        memset(pos, 0, sizeof(pos));
        for (int j = 1; j <= n * 2; j++)
        {
            all[j] = read();
            pos[all[j]] += j;
        }
        bool s = func(n, 1); //从左开始
        if (s == false) //从右开始
        {
            s = func(n, n * 2);
        }
        if (s == false)
        {
            printf("-1\n");
        }
    }
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}