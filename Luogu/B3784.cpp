#include <algorithm>
#include <iostream>
using namespace std;
struct Song
{
    int id, h;
    bool operator<(const Song oth) const
    {
        return h > oth.h;
    }
};
Song sgs[100005];
int read();
int main()
{
    int n = read(), m = read(), a = read(), b = read(), she = 0;
    for (int i = 1; i <= n; i++)
    {
        sgs[i].id = i;
    }
    for (int i = 1; i <= a; i++)
    {
        int maxh = -1, fav = 0;
        for (int j = 1; j <= n; j++)
        {
            int h = read();
            sgs[j].h += h;
            if (maxh < h)
            {
                maxh = h, fav = j;
            }
        }
        if (i == b)
        {
            she = fav;
        }
    }
    sort(sgs + 1, sgs + 1 + n);
    int ok = 0;
    for (int i = 1; i <= m; i++)
    {
        if (sgs[i].id == she)
        {
            ok = 1;
            break;
        }
    }
    if (ok)
    {
        printf("%d ", she);
        for (int i = 1; i <= m; i++)
        {
            if (sgs[i].id == she)
            {
                continue;
            }
            printf("%d ", sgs[i].id);
        }
    }
    else
    {
        for (int i = 1; i < m; i++)
        {
            printf("%d ", sgs[i].id);
        }
        printf("%d ", she);
    }
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