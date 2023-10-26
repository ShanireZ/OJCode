#include <algorithm>
#include <iostream>
using namespace std;
int v[505][505], qz[505][505], r, c, a, b;
bool check(int lim)
{
    int ca = 0, pre = 0; // ch当前横着几块 pre上一刀位置
    for (int i = 1; i <= r; i++)
    {
        int cb = 0, tot = 0; // cl当前竖着几块 tot当前这块的和
        for (int j = 1; j <= c; j++)
        {
            tot += qz[i][j] - qz[i][j - 1] - qz[pre][j] + qz[pre][j - 1];
            if (tot >= lim)
            {
                cb++, tot = 0;
            }
        }
        if (cb >= b)
        {
            ca++, pre = i;
        }
    }
    if (ca >= a)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> r >> c >> a >> b;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> v[i][j];
            qz[i][j] = qz[i - 1][j] + qz[i][j - 1] - qz[i - 1][j - 1] + v[i][j];
        }
    }
    int L = 1, R = qz[r][c];
    while (L <= R)
    {
        int mid = (L + R) / 2;
        check(mid) ? L = mid + 1 : R = mid - 1;
    }
    cout << R << endl;
    return 0;
}
// TAG: 二分答案 二维前缀和 枚举