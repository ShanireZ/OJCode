#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define MX 100005
#define INF 10000000000ll
int n, m, x0, tar[2][MX][20], read();
long long h[MX], da[2][MX][20], db[2][MX][20];
struct City
{
    int id;
    long long ht;
    bool operator<(const City oth) const
    {
        return ht < oth.ht;
    }
};
City nr[10];
multiset<City> cs;
pair<long long, long long> count(int s, int x) //* 计算以s为起点,每人的行进距离
{
    long long la = 0, lb = 0;
    for (int i = 19; i >= 0; i--)
    {
        if (tar[0][s][i] && la + lb + da[0][s][i] + db[0][s][i] <= x)
        {
            la += da[0][s][i], lb += db[0][s][i];
            s = tar[0][s][i];
        }
    }
    return make_pair(la, lb);
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        h[i] = read();
    }
    cs.insert(City{0, INF}), cs.insert(City{0, INF});
    cs.insert(City{0, -INF}), cs.insert(City{0, -INF});
    for (int i = n; i >= 1; i--) //* 1.填充 tar da db 初始值
    {
        auto p1 = cs.lower_bound(City{i, h[i]});
        auto p2 = p1;
        nr[1] = *p1, nr[2] = *(--p2);
        nr[3] = *(++p1), nr[4] = *(--p2);
        City a = City{0, INF}, b = City{0, INF}; //* a次小 b最小
        for (int j = 1; j <= 4; j++)
        {
            if (abs(nr[j].ht - h[i]) < abs(h[i] - b.ht) || (abs(nr[j].ht - h[i]) == abs(h[i] - b.ht) && nr[j].ht < b.ht))
            {
                a = b, b = nr[j];
            }
            else if (abs(nr[j].ht - h[i]) < abs(h[i] - a.ht) || (abs(nr[j].ht - h[i]) == abs(h[i] - a.ht) && nr[j].ht < a.ht))
            {
                a = nr[j];
            }
        }
        tar[0][i][0] = a.id, tar[1][i][0] = b.id;
        da[0][i][0] = abs(a.ht - h[i]), db[1][i][0] = abs(b.ht - h[i]);
        cs.insert(City{i, h[i]});
    }
    for (int k = 1; k < 20; k++) //* 2.三层循环计算 tar da db
    {
        for (int j = 1; j <= n; j++)
        {
            for (int i = 0; i < 2; i++)
            {
                int pos = (k == 1 ? 1 - i : i); //* 中间点
                tar[i][j][k] = tar[pos][tar[i][j][k - 1]][k - 1];
                da[i][j][k] = da[i][j][k - 1] + da[pos][tar[i][j][k - 1]][k - 1];
                db[i][j][k] = db[i][j][k - 1] + db[pos][tar[i][j][k - 1]][k - 1];
            }
        }
    }
    x0 = read(), m = read();
    int s0 = 0;
    double minp = 1e20;
    for (int i = 1; i <= n; i++) //* 3.枚举每个点为起点 求解问题1
    {
        pair<long long, long long> now = count(i, x0);
        double nowp = 1.0 * now.first / now.second;
        if (nowp < minp || (nowp == minp && h[i] > h[s0]))
        {
            minp = nowp, s0 = i;
        }
    }
    printf("%d\n", s0);
    for (int i = 1; i <= m; i++) //* 4.求解问题2
    {
        int s = read(), x = read();
        pair<long long, long long> now = count(s, x);
        printf("%lld %lld\n", now.first, now.second);
    }
    return 0;
}
int read()
{
    int ans = 0, tag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        tag = (ch == '-') ? -1 : 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * tag;
}
// TAG: DP 倍增