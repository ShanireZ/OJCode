#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
#define MX 150005
#define LC ns[now].lc
#define RC ns[now].rc
struct Node
{
    int lc, rc, lz, a, wn; // lz:擂主左右 a:胜者能力值 y:阈值范围
};
Node ns[MX * 2];
long long res[MX], ans;
int a[MX], oa[MX], c[MX], ox[5], cnt[20], n, m, T, root, npos, cs;
string ds[20];
void init(int &now, int h)
{
    now = ++npos, cnt[h]++;
    if (h == 0)
    {
        ns[now].a = a[cnt[h]], ns[now].wn = cnt[h];
        return;
    }
    ns[now].lz = ds[h][cnt[h] - 1] - '0';
    init(LC, h - 1), init(RC, h - 1);
    ns[now].wn = (ns[now].lz == 0 && ns[LC].a >= h) ? ns[LC].wn : ns[RC].wn;
    ns[now].a = ((ns[now].lz == 0 && ns[LC].a >= h) || (ns[now].lz == 1 && ns[RC].a < h)) ? ns[LC].a : ns[RC].a;
}
void dfs(int now, int lmt, int h, int l, int r)
{
    if (l > r)
    {
        return;
    }
    if (h == 0)
    {
        int pos = ns[now].wn;
        if (l < min(r, pos)) // pos的值如果不定,则区间[L, R) [L, pos) 交集部分+pos
        {
            res[l] += pos, res[min(r, pos)] -= pos;
        }
        if (a[pos] >= lmt && max(pos, l) < r) // 能力值满足限制,区间[L, R) [pos, R) 交集部分+pos
        {
            res[max(pos, l)] += pos, res[r] -= pos;
        }
        return;
    }
    if (ns[now].lz == 0)
    {
        dfs(LC, max(lmt, h), h - 1, l, r);                             // 擂主要满足祖先限制
        dfs(RC, lmt, h - 1, l, ns[LC].a >= h ? min(r, ns[LC].wn) : r); // 右子树只有在左子树不确定时才能胜出
    }
    else
    {
        dfs(LC, lmt, h - 1, l, ns[RC].a >= h ? min(r, ns[RC].wn) : r); // 左子树只有在右子树不确定时才能胜出
        dfs(RC, max(lmt, h), h - 1, l, r);                             // 擂主要满足祖先限制
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cs = __lg(n - 1) + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> oa[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= cs; i++)
    {
        cin >> ds[i];
    }
    cin >> T;
    while (T--)
    {
        npos = root = ans = 0;
        for (int i = 0; i <= n; i++)
        {
            res[i] = 0;
        }
        for (int i = 0; i <= cs; i++)
        {
            cnt[i] = 0;
        }
        cin >> ox[0] >> ox[1] >> ox[2] >> ox[3];
        for (int i = 1; i <= n; i++)
        {
            a[i] = oa[i] ^ ox[i % 4];
        }
        init(root, cs);
        for (int i = 0, ex = 1; i <= cs; i++, ex *= 2)
        {
            dfs(cs + 1 - i, 0, i, ex / 2 + 1, ex + 1);
        }
        for (int i = 1; i <= n; i++)
        {
            res[i] += res[i - 1];
        }
        for (long long i = 1; i <= m; i++)
        {
            ans ^= i * res[c[i]];
        }
        cout << ans << endl;
    }
    return 0;
}