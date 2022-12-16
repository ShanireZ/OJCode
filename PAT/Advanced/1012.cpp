#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define MX 10005
struct Stu
{
    string id;
    int c, m, e, a;
};
Stu stu[MX];
map<string, int[5]> rk;
bool cmpa(Stu x, Stu y)
{
    return x.a > y.a;
}
bool cmpc(Stu x, Stu y)
{
    return x.c > y.c;
}
bool cmpm(Stu x, Stu y)
{
    return x.m > y.m;
}
bool cmpe(Stu x, Stu y)
{
    return x.e > y.e;
}
int main() // 单科排名+科目优先顺序+同分同排名
{
    char opt[5] = {'A', 'C', 'M', 'E'};
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].a = round((stu[i].c + stu[i].m + stu[i].e) / 3.0);
    }
    stu[0].a = stu[0].c = stu[0].m = stu[0].e = -1;
    sort(stu + 1, stu + n + 1, cmpa);
    for (int i = 1; i <= n; i++)
    {
        rk[stu[i].id][0] = (stu[i].a == stu[i - 1].a) ? rk[stu[i - 1].id][0] : i;
    }
    sort(stu + 1, stu + n + 1, cmpc);
    for (int i = 1; i <= n; i++)
    {
        rk[stu[i].id][1] = (stu[i].c == stu[i - 1].c) ? rk[stu[i - 1].id][1] : i;
    }
    sort(stu + 1, stu + n + 1, cmpm);
    for (int i = 1; i <= n; i++)
    {
        rk[stu[i].id][2] = (stu[i].m == stu[i - 1].m) ? rk[stu[i - 1].id][2] : i;
    }
    sort(stu + 1, stu + n + 1, cmpe);
    for (int i = 1; i <= n; i++)
    {
        rk[stu[i].id][3] = (stu[i].e == stu[i - 1].e) ? rk[stu[i - 1].id][3] : i;
    }
    for (int i = 1; i <= m; i++)
    {
        string id;
        cin >> id;
        int ans = 0;
        for (int j = 1; j < 4; j++)
        {
            if (rk[id][j] < rk[id][ans])
            {
                ans = j;
            }
        }
        if (rk[id][ans] == 0)
        {
            cout << "N/A\n";
        }
        else
        {
            cout << rk[id][ans] << " " << opt[ans] << "\n";
        }
    }
    return 0;
}