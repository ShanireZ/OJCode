#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define LC ns[now].lc
#define RC ns[now].rc
#define MX 100005
struct Line
{
    int x, yup, ydown, status;
    bool operator<(const Line oth) const
    {
        return x < oth.x;
    }
};
Line lines[MX * 2];
struct Node
{
    int v, lc, rc, len, times;
    //* v当前区间被实际覆盖长度 lc/rc左右子节点编号 len当前区间最大长度 times当前区间被覆盖次数
};
Node ns[MX * 80];
vector<int> ls;
int pos, root, read();
void maketree(int &now, int l, int r) //* 建立线段树
{
    now = ++pos;
    if (l == r)
    {
        ns[now].len = ls[l] - ls[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    maketree(LC, l, mid), maketree(RC, mid + 1, r);
    ns[now].len = ns[LC].len + ns[RC].len;
}
void edit(int now, int l, int r, int x, int y, int k) //* 修改x-y区间的值
{
    if (l >= x && r <= y)
    {
        ns[now].times += k;
        ns[now].v = (ns[now].times ? ns[now].len : ns[LC].v + ns[RC].v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
    {
        edit(LC, l, mid, x, y, k);
    }
    if (y > mid)
    {
        edit(RC, mid + 1, r, x, y, k);
    }
    ns[now].v = (ns[now].times ? ns[now].len : ns[LC].v + ns[RC].v);
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        lines[i * 2 - 1].x = x1, lines[i * 2].x = x2; // 左右两侧
        lines[i * 2 - 1].status = 1, lines[i * 2].status = -1;
        lines[i * 2 - 1].ydown = lines[i * 2].ydown = y1;
        lines[i * 2 - 1].yup = lines[i * 2].yup = y2;
        ls.push_back(y1), ls.push_back(y2);
    }
    sort(lines + 1, lines + 1 + n * 2);
    sort(ls.begin(), ls.end());
    int sz = ls.erase(unique(ls.begin(), ls.end()), ls.end()) - ls.begin();
    //* 线段树加速扫描线
    //* 线段树中区域1表示坐标系0~1区间覆盖次数 2表示1~2 ... sz-1表示sz-2~sz-1
    maketree(root, 1, sz - 1);
    long long tot = 0, xpos = 0; //*xpos为上条扫描线X轴位置
    for (int i = 1; i <= n * 2; i++)
    {
        tot += (lines[i].x - xpos) * ns[root].v;
        int yup = lower_bound(ls.begin(), ls.end(), lines[i].yup) - ls.begin();
        int ydown = lower_bound(ls.begin(), ls.end(), lines[i].ydown) - ls.begin();
        edit(root, 1, sz - 1, ydown + 1, yup, lines[i].status);
        xpos = lines[i].x;
    }
    printf("%lld\n", tot);
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