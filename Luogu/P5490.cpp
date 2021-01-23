#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int read(); //快读
struct Line
{
    int x, yup, ydown, status;
};
bool cmp(Line a, Line b)
{
    return a.x < b.x;
}
Line lines[200005];
vector<int> ls;
struct Node
{
    int v, lc, rc, len, times;
    //* v当扫描线高度 lc rc左右子节点编号 len当前扫描线理论高度 times当前扫描线是否存在出现几次
};
Node ns[800005];
int pos;
void maketree(int l, int r, int &now) //* 建立线段树
{
    now = ++pos;
    if (l == r)
    {
        ns[now].len = ls[l] - ls[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    maketree(l, mid, ns[now].lc);
    maketree(mid + 1, r, ns[now].rc);
    ns[now].len = ns[ns[now].lc].len + ns[ns[now].rc].len;
}
void check(int now)
{
    if (ns[now].times > 0) //* 如果当前区间整段出现
    {
        ns[now].v = ns[now].len;
    }
    else //* 如果只是部分出现
    {
        ns[now].v = ns[ns[now].lc].v + ns[ns[now].rc].v;
    }
}
void edit(int l, int r, int now, int k, int x, int y) //* 修改x-y区间的值
{
    if (l == x && r == y) //* 找到目标区间 修改出现次数 并更新当前节点信息
    {
        ns[now].times += k;
        check(now);
        return;
    }
    int mid = (l + r) / 2; //* 递归查找下层
    if (x <= mid && y >= l)
    {
        edit(l, mid, ns[now].lc, k, max(x, l), min(y, mid));
    }
    if (y >= mid + 1 && x <= r)
    {
        edit(mid + 1, r, ns[now].rc, k, max(x, mid + 1), min(y, r));
    }
    check(now); //* 递归结束 更新当前节点信息
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        lines[i * 2 - 1].x = x1; //*左侧边
        lines[i * 2].x = x2;     //*右侧边
        lines[i * 2 - 1].ydown = lines[i * 2].ydown = y1;
        lines[i * 2 - 1].yup = lines[i * 2].yup = y2;
        lines[i * 2 - 1].status = 1;
        lines[i * 2].status = -1;
        ls.push_back(y1);
        ls.push_back(y2);
    }
    sort(lines + 1, lines + 1 + n * 2, cmp);
    sort(ls.begin(), ls.end());
    unique(ls.begin(), ls.end());
    //* 线段树加速扫描线
    //* 区间为下标 1 ~ size()-1 表示 0~1 1~2 2~3...
    int root = 0;
    maketree(1, ls.size() - 1, root);
    long long tot = 0, xpos = 0; //*xpos为上条扫描线X轴位置
    for (int i = 1; i <= n * 2; i++)
    {
        tot += (lines[i].x - xpos) * ns[root].v;
        int yup = lower_bound(ls.begin(), ls.end(), lines[i].yup) - ls.begin();
        int ydown = lower_bound(ls.begin(), ls.end(), lines[i].ydown) - ls.begin();
        edit(1, ls.size() - 1, root, lines[i].status, ydown + 1, yup);
        xpos = lines[i].x;
    }
    printf("%lld", tot);
    return 0;
}
int read()
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