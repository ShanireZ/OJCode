#include <iostream>
using namespace std;
int ms[9][2] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {0, 0}};
long long qp[25][25]; //! qp[bx][by] 答案
int ma[25][25];
int main()//! 递推
{
    int bx, by, mx, my;
    cin >> bx >> by >> mx >> my;
    for (int i = 0; i <= 8; i++) //! 马的控制点
    {
        int x = mx + ms[i][0], y = my + ms[i][1];
        if (x < 0 || x > bx || y < 0 || y > by)
        {
            continue;
        }
        ma[x][y] = 1;
    }
    qp[0][0] = 1;
    for (int i = 0; i <= bx; i++) //! 统计方案数
    {
        for (int j = 0; j <= by; j++)
        {
            if (ma[i][j] == 1)
            {
                continue;
            }
            if (j - 1 >= 0)
            {
                qp[i][j] += qp[i][j - 1];
            }
            if (i - 1 >= 0)
            {
                qp[i][j] += qp[i - 1][j];
            }
        }
    }
    cout << qp[bx][by] << endl;
    return 0;
}