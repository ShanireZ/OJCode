#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Seg
{
    int x, yup, ydown, status;
};
Seg seg[2005];
bool cmp(Seg a, Seg b)
{
    return a.x < b.x;
}
vector<int> ls;
int vis[2005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ls.push_back(y1);
        ls.push_back(y2);
        seg[i * 2 - 1].x = x1; //* 左边
        seg[i * 2].x = x2;     //* 右边
        seg[i * 2 - 1].yup = seg[i * 2].yup = y1;
        seg[i * 2 - 1].ydown = seg[i * 2].ydown = y2;
        seg[i * 2 - 1].status = 1;
        seg[i * 2].status = -1;
    }
    sort(ls.begin(), ls.end());
    unique(ls.begin(), ls.end());        //* y坐标离散化
    sort(seg + 1, seg + 1 + n * 2, cmp); //* 扫描线 将竖直边按照顺序排列
    long long tot = 0, xpos = 0, ylen = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        tot += (seg[i].x - xpos) * ylen; //* 统计前方图形面积
        seg[i].yup = lower_bound(ls.begin(), ls.end(), seg[i].yup) - ls.begin();
        seg[i].ydown = lower_bound(ls.begin(), ls.end(), seg[i].ydown) - ls.begin();
        if (seg[i].status == 1)
        {
            vis[seg[i].ydown]++;
            vis[seg[i].yup]--;
        }
        else
        {
            vis[seg[i].ydown]--;
            vis[seg[i].yup]++;
        }
        int cnt = 0;
        ylen = 0;
        for (int j = 0; j < ls.size(); j++) //* 统计当前y坐标宽度
        {
            if (cnt)
            {
                ylen += ls[j] - ls[j - 1];
            }
            cnt += vis[j];
        }
        xpos = seg[i].x;
    }
    cout << tot;
    return 0;
}