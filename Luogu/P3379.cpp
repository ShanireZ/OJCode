#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[500005];
int anc[500005][25];
int lk[1000005][2]; //存储所有路径 [0] 路径的目标点id [1] 上一条同源路径id
int tree[500005];   //存储最后一条连接该点的路径id
void make(int x, int step)
{
    dp[x] = step;
    for (int i = 1; i <= log2(dp[x]); i++) //将x的祖先安排到位
    {
        int id = anc[x][i - 1];
        anc[x][i] = anc[id][i - 1];
    }
    for (int i = tree[x]; lk[i][0] != 0; i = lk[i][1]) //查找x的子节点
    {
        int id = lk[i][0];
        if (dp[id] == 0)
        {
            anc[id][0] = x;
            make(id, step + 1);
        }
    }
}
void lca(int a, int b)
{
    if (dp[b] > dp[a])
    {
        swap(a, b);
    }
    if (dp[a] != dp[b]) //如果a b深度不同 将a提升到b的深度
    {
        for (int i = log2(dp[a] - dp[b]); i >= 0; i--)
        {
            if (dp[a] - pow(2, i) >= dp[b])
            {
                a = anc[a][i];
            }
        }
    }
    if (a == b) //如果此时a b重合
    {
        printf("%d\n", a);
        return;
    }
    for (int i = log2(dp[a]); i >= 0; i--) //不断向上 寻找lca
    {
        if (anc[a][i] != anc[b][i])
        {
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    printf("%d\n", anc[a][0]);
}
int rd() //正数快读
{
    char ch = getchar();
    int x = 0;
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x * 10) + (ch - '0');
        ch = getchar();
    }
    return x;
}
int main()
{
    int n = rd(), m = rd(), s = rd();
    int x, y;
    for (int i = 1; i < n; i++)
    {
        x = rd(), y = rd();
        //数组模拟向前链表
        lk[2 * i - 1][0] = y;
        lk[2 * i - 1][1] = tree[x];
        tree[x] = 2 * i - 1;
        lk[2 * i][0] = x;
        lk[2 * i][1] = tree[y];
        tree[y] = 2 * i;
    }
    make(s, 1);
    for (int i = 1; i <= m; i++)
    {
        x = rd(), y = rd();
        lca(x, y);
    }
    return 0;
}