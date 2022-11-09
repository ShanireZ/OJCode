#include <algorithm>
#include <cstdio>
using namespace std;
struct Node
{
    int v, st, tar;
};
Node sa[1005], sb[1005];
bool cmpv(Node a, Node b)
{
    return a.v < b.v;
}
bool cmpst(Node a, Node b)
{
    return a.st < b.st;
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
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), t = 0;
        for (int i = 1; i <= n; i++)
        {
            sa[i].v = read(), sa[i].st = i;
        }
        sort(sa + 1, sa + 1 + n, cmpv);
        for (int i = 1; i <= n; i++)
        {
            sb[i].v = read(), sb[i].st = i;
        }
        sort(sb + 1, sb + 1 + n, cmpv);
        for (int i = 1; i <= n; i++)
        {
            sa[i].tar = sb[i].st;
            if (sa[i].v != sb[i].v)
            {
                t = 1;
                break;
            }
        }
        if (t == 1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        sort(sa + 1, sa + 1 + n, cmpst);
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j < i; j++)
            {
                if (sa[j].tar > sa[j + 1].tar)
                {
                    printf("%d %d\n", j, j + 1);
                    swap(sa[j], sa[j + 1]);
                }
            }
        }
        printf("0 0\n");
    }
    return 0;
}