#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Stu
{
    int id, score, tid;
};
Stu stu[1005];
int team[30][105];
bool cmp(Stu a, Stu b)
{
    if (a.score == b.score)
    {
        return a.tid < b.tid;
    }
    return a.score > b.score;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int s;
        char ch;
        cin >> s >> ch;
        stu[i].id = i;
        stu[i].score = s;
        stu[i].tid = ch - ('A' - 1);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int s;
            cin >> s;
            team[j][101] += s;
            team[j][s]++;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        double avgs = 1.0 * team[i][101] / k; //此处不进行舍入 严格控制+-15分内
        int tot = 0, cnt = 0;
        int st = ceil(avgs - 15), ed = avgs + 15;
        for (int j = max(0, st); j <= min(100, ed); j++)
        {
            cnt += team[i][j];
            tot += team[i][j] * j;
        }
        team[i][0] = round(1.0 * tot / cnt);
    }
    for (int i = 1; i <= n; i++)
    {
        stu[i].score = round(0.6 * stu[i].score + 0.4 * team[stu[i].tid][0]);
    }
    sort(stu + 1, stu + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << stu[i].score << " " << char(stu[i].tid + ('A' - 1)) << endl;
    }
    return 0;
}