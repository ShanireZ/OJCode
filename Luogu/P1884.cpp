#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Seg
{
    int x, yup, ydown, op;
};
Seg seg[2005];
bool cmp(Seg a, Seg b)
{
    return a.x < b.x;
}
int n, pos, cfy[2005], ls[2005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ls[i * 2 - 1] = y1, ls[i * 2] = y2;
        seg[i * 2 - 1] = Seg{x1, y1, y2, 1}; // 左
        seg[i * 2] = Seg{x2, y1, y2, -1};    // 右
    }
    sort(ls + 1, ls + 1 + n * 2), sort(seg + 1, seg + 1 + n * 2, cmp);
    pos = unique(ls + 1, ls + 1 + n * 2) - ls - 1;
    long long tot = 0, xpre = 0, ylen = 0;
    for (int i = 1; i <= n + n; i++)
    {
        seg[i].yup = lower_bound(ls + 1, ls + 1 + pos, seg[i].yup) - ls;
        seg[i].ydown = lower_bound(ls + 1, ls + 1 + pos, seg[i].ydown) - ls;
        tot += (seg[i].x - xpre) * ylen, xpre = seg[i].x;
        (seg[i].op == 1) ? (cfy[seg[i].ydown]++, cfy[seg[i].yup]--)
                         : (cfy[seg[i].ydown]--, cfy[seg[i].yup]++);
        ylen = 0;
        for (int j = 1, cnt = 0; j <= pos; j++)
        {
            if (cnt)
            {
                ylen += ls[j] - ls[j - 1];
            }
            cnt += cfy[j];
        }
    }
    cout << tot << endl;
    return 0;
}