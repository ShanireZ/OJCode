#include <iostream>
using namespace std;
int ord[105], lvl[105], cow[105];
//ord[i]为第i个挤奶的奶牛编号 lvl[i]为级别为i的奶牛编号 cow[i]为编号为i的奶牛的挤奶名次
int main()
{
    int n, m, k, havelv = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> lvl[i];
        if (lvl[i] == 1)
        {
            havelv = 1;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int c, p;
        cin >> c >> p;
        ord[p] = c;
        cow[c] = p;
    }
    //如果1号奶牛有级别，那么我们需要将所有有级别的奶牛尽可能前置
    //如果1号奶牛没有级别，那么我们需要将所有有级别的奶牛尽可能后置
    //havelv表示1号奶牛是否有级别
    if (havelv)
    {
        int pos = 1;
        for (int i = 1; i <= m; i++)
        {
            int id = lvl[i];
            if (cow[id]) //该奶牛已经放置完成 后续级别奶牛放置在他后面
            {
                pos = cow[id];
                continue;
            }
            while (ord[pos]) //找空位
            {
                pos++;
            }
            ord[pos] = id;
            cow[id] = pos;
        }
    }
    else
    {
        int pos = n;
        for (int i = m; i >= 1; i--)
        {
            int id = lvl[i];
            if (cow[id])
            {
                pos = cow[id];
                continue;
            }
            while (ord[pos])
            {
                pos--;
            }
            ord[pos] = id;
            cow[id] = pos;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ord[i] == havelv)
        {
            cout << i;
            break;
        }
    }
    return 0;
}