#include <iostream>
using namespace std;
struct Node
{
    int l, r, v;
};
Node ns[200005];
int vis[200005], read();
int main()
{
    int n = read(), pos = 0;
    ns[0].v = -1;
    for (int i = 1; i <= n; i++)
    {
        int opt = read();
        if (opt != ns[pos].v)
        {
            ns[++pos] = Node{i, i, opt};
        }
        ns[pos].r = i;
    }
    while (pos)
    {
        int npos = 0;
        for (int i = 1; i <= pos; i++)
        {
            printf("%d ", ns[i].l), vis[ns[i].l] = 1;
            while (vis[ns[i].l] && ns[i].l <= ns[i].r)
            {
                ns[i].l++;
            }
            if (ns[i].l <= ns[i].r)
            {
                if (ns[i].v != ns[npos].v)
                {
                    ns[++npos] = ns[i];
                }
                ns[npos].r = ns[i].r;
            }
        }
        printf("\n"), pos = npos;
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