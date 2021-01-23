#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int l, r, v, idx, size;
};
Node ns[300005];
int root, pos, n, minx, tag, tot, a, b;
int newnode(int v)
{
    ns[++pos].v = v;
    ns[pos].idx = rand();
    ns[pos].size = 1;
    return pos;
}
void updsize(int now)
{
    ns[now].size = ns[ns[now].l].size + ns[ns[now].r].size + 1;
}
void split(int now, int v, int &x, int &y)
{
    if (now == 0)
    {
        x = y = 0;
        return;
    }
    if (ns[now].v <= v)
    {
        x = now;
        split(ns[now].r, v, ns[x].r, y);
    }
    else
    {
        y = now;
        split(ns[now].l, v, x, ns[y].l);
    }
    updsize(now);
}
int merge(int x, int y) //x小 y大
{
    if (x == 0 || y == 0)
    {
        return x + y;
    }
    if (ns[x].idx <= ns[y].idx) //合并规则 随便写
    {
        ns[x].r = merge(ns[x].r, y);
        updsize(x);
        return x;
    }
    else
    {
        ns[y].l = merge(x, ns[y].l);
        updsize(y);
        return y;
    }
}
void insert(int x)
{
    if (x < minx) //特判
    {
        return;
    }
    tot++;                      //人数+1 增员操作
    split(root, x - tag, a, b); //插入的值为预处理之后的值
    root = merge(merge(a, newnode(x - tag)), b);
}
void add(int x)
{
    tag += x;
}
void reduce(int x)
{
    tag -= x;
    split(root, minx - tag - 1, a, b); //找到此时的离职人员 分到a中清空
    root = b;
    tot = ns[b].size; //现存人数更新
}
void find_rkx(int x)
{
    if (x > tot) //特判
    {
        cout << -1 << endl;
        return;
    }
    x = tot - x + 1; //第x大为第tot-x+1小
    int now = root;
    while (now)
    {
        if (ns[ns[now].l].size + 1 == x)
        {
            break;
        }
        else if (ns[ns[now].l].size >= x)
        {
            now = ns[now].l;
        }
        else
        {
            x -= ns[ns[now].l].size + 1;
            now = ns[now].r;
        }
    }
    cout << ns[now].v + tag << endl;
}
int main()
{
    srand(233);
    cin >> n >> minx;
    for (int i = 1; i <= n; i++)
    {
        char x;
        int k;
        cin >> x >> k;
        if (x == 'I') //插入k
        {
            insert(k);
        }
        else if (x == 'A') //加工资
        {
            add(k);
        }
        else if (x == 'S') //减工资
        {
            reduce(k);
        }
        else if (x == 'F') //查询rank为k的值
        {
            find_rkx(k);
        }
    }
    cout << pos - tot << endl;
    return 0;
}