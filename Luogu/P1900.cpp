#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set<int> vis; //存储非selfnumber
struct Node
{
    int ask, id, v;
};
Node ns[5005]; //存储所有询问
bool cmp1(Node a, Node b)
{
    return a.ask < b.ask;
}
bool cmp2(Node a, Node b)
{
    return a.id < b.id;
}
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
int main()
{
    int n = read(), k = read(), cnt = 0, pos = 1;
    for (int i = 1; i <= k; i++)
    {
        ns[i].ask = read();
        ns[i].id = i;
    }
    sort(ns + 1, ns + 1 + k, cmp1);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis.size() == 0 || *vis.begin() != i) //i为自我数
        {
            cnt++;
            while (ns[pos].ask == cnt) //当前自我数是要寻找的自我数 有可能重复找同一个数
            {
                ns[pos].v = i;
                pos++;
            }
        }
        else
        {
            vis.erase(vis.begin());
        }
        tot++; //当前所有位数和 每下一个新数和+1 每进一位和-9
        int tmp = i;
        while (tmp % 10 == 0)
        {
            tot -= 9;
            tmp /= 10;
        }
        int ans = i + tot;
        vis.insert(ans);
    }
    printf("%d\n", cnt);
    sort(ns + 1, ns + 1 + k, cmp2);
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", ns[i].v);
    }
    return 0;
}