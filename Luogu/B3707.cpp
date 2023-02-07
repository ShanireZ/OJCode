#include <algorithm>
#include <iostream>
using namespace std;
int m[10][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int x[5][2] = {{2, 2}, {-2, -2}, {2, -2}, {-2, 2}};
int main()
{
    int p, x0, y0, x1, y1, ans = 0;
    scanf("%d %d %d %d %d", &p, &x0, &y0, &x1, &y1);
    if (p == 1 && (x0 == x1 || y0 == y1))
    {
        ans = 1;
    }
    else if (p == 3)
    {
        for (int i = 0; i < 8; i++)
        {
            if (x0 + m[i][0] == x1 && y0 + m[i][1] == y1)
            {
                ans = 1;
                break;
            }
        }
    }
    else if (p == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (x0 + x[i][0] == x1 && y0 + x[i][1] == y1)
            {
                ans = 1;
                break;
            }
        }
    }
    (ans == 0) ? printf("No\n") : printf("Yes\n");
    return 0;
}