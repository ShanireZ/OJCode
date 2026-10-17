#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>
using namespace std;
struct Node
{
    double x, y;
};
Node a, b, c, d, v1, v2;
struct Pt
{
    double t1, t2, tall, v1, v2, best1, best2, bestAll;
};
Pt pts[1005];
double p, q, r, tab, tcd, c1, c2, best1, best2, bestAll;
int cnt, rounds;
double rnd()
{
    return 1.0 * rand() / RAND_MAX;
}
double w(int nowR)
{
    // w慣性系數取值範圍[0.4, 2]
    // 慣性系數越大全域探索能力越強，越小局部探索能力越強。初期全域探索，後期收斂到局部探索
    return 1.8 - (1.8 - 0.9) * nowR / rounds;
}
double dis(Node a, Node b) // 兩點間距離
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double makeAns(double t1, double t2)
{
    Node n1 = Node{a.x + v1.x * t1, a.y + v1.y * t1}; // 根據隨機時間t1定位到AB上某點
    Node n2 = Node{d.x - v2.x * t2, d.y - v2.y * t2}; // 根據隨機時間t2定位到CD上某點
    return t1 + t2 + dis(n1, n2) / r;
}
void check(double &t, double &v, double lim)
{
    lim = abs(lim);
    if (v > lim * 0.15 || v < lim * -0.15) // 設定了vmax，防止速度過快
    {
        v = lim * (v > 0 ? 0.15 : -0.15);
    }
    t += v;
    if (t > lim || t < 0) // 撞到邊界反轉
    {
        v = -v, t = (t < 0 ? 0 : lim);
    }
}
void update(int id, int nowR)
{
    pts[id].v1 = pts[id].v1 * w(nowR) + c1 * rnd() * (pts[id].best1 - pts[id].t1) + c2 * rnd() * (best1 - pts[id].t1);
    pts[id].v2 = pts[id].v2 * w(nowR) + c1 * rnd() * (pts[id].best2 - pts[id].t2) + c2 * rnd() * (best2 - pts[id].t2);
    check(pts[id].t1, pts[id].v1, tab), check(pts[id].t2, pts[id].v2, tcd);
    pts[id].tall = makeAns(pts[id].t1, pts[id].t2);
    if (pts[id].tall < pts[id].bestAll)
    {
        pts[id].bestAll = pts[id].tall, pts[id].best1 = pts[id].t1, pts[id].best2 = pts[id].t2;
    }
}
int main()
{
    srand(time(0));
    c1 = 1.6, c2 = 1.8, cnt = 1000, rounds = 1000, best1 = best2 = bestAll = 1e12;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> p >> q >> r;
    tab = dis(a, b) / p, tcd = dis(c, d) / q;
    v1 = (tab == 0 ? Node{0, 0} : Node{(b.x - a.x) / tab, (b.y - a.y) / tab});
    v2 = (tcd == 0 ? Node{0, 0} : Node{(d.x - c.x) / tcd, (d.y - c.y) / tcd});
    for (int i = 1; i <= cnt; i++) // 生成粒子群
    {
        pts[i].v1 = pts[i].v2 = 0;
        pts[i].best1 = pts[i].t1 = tab * rnd(), pts[i].best2 = pts[i].t2 = tcd * rnd();
        pts[i].bestAll = pts[i].tall = makeAns(pts[i].t1, pts[i].t2);
        if (pts[i].bestAll < bestAll)
        {
            bestAll = pts[i].bestAll, best1 = pts[i].best1, best2 = pts[i].best2;
        }
    }
    for (int i = 1; i <= rounds; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            update(j, i);
            if (pts[j].bestAll < bestAll)
            {
                bestAll = pts[j].bestAll, best1 = pts[j].best1, best2 = pts[j].best2;
            }
        }
    }
    cout << fixed << setprecision(2) << bestAll << endl;
    return 0;
}
// TAG: 三分法 模擬退火 微粒群優化