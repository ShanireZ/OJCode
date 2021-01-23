#include <cstdio>
#include <algorithm>
using namespace std;
int read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    int t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}
struct Node
{
    int s, p;
};
bool cmp(Node a, Node b)
{
    return a.p < b.p;
}
Node ns[100005];
int main()
{
    int n = read(), st = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].s = read();
        ns[i].p = read();
    }
    sort(ns + 1, ns + 1 + n, cmp); //将所有草垛排序
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) //找到初始的位置
    {
        if (st < ns[i].p)
        {
            r = i;
            l = i - 1;
            break;
        }
    }
    if (l == 0 || r == 0) //如果初始就在外面
    {
        printf("-1");
        return 0;
    }
    int minadd = 0x3f3f3f3f;
    //加固左边
    int trig = 0, pos = r;
    for (int i = l; i >= 1; i--) //枚举左端
    {
        //找到当前左端下 第一个守住的右端
        //下一个左端枚举时 从此pos位置继续即可
        //因为前方的右端连较少的冲击都防御不住 下一个左端范围扩大肯定更守不住
        for (int j = pos; j <= n; j++)
        {
            int d = ns[j].p - ns[i].p;
            if (d <= ns[j].s)
            {
                int add = max(d - ns[i].s, (int)0);
                minadd = min(minadd, add);
                pos = j;
                break;
            }
            if (j == n) //如果最右端失守
            {
                trig = 1;
            }
        }
        if (trig)
        {
            break;
        }
    }
    //加固右边
    trig = 0, pos = l;
    for (int i = r; i <= n; i++) //枚举右端 原理同上
    {
        for (int j = pos; j >= 1; j--)
        {
            int d = ns[i].p - ns[j].p;
            if (d <= ns[j].s)
            {
                int add = max(d - ns[i].s, (int)0);
                minadd = min(minadd, add);
                pos = j;
                break;
            }
            if (j == 1)
            {
                trig = 1;
            }
        }
        if (trig)
        {
            break;
        }
    }
    if (minadd == 0x3f3f3f3f)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", minadd);
    }
    return 0;
}