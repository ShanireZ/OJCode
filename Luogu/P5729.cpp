#include <iostream>
using namespace std;
int a[25][25][25];
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int q;
    cin >> q;
    int tot = w * x * h;
    for (int t = 1; t <= q; t++)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                for (int k = z1; k <= z2; k++)
                {
                    if (a[i][j][k] == 0)
                    {
                        a[i][j][k] = 1;
                        tot--;
                    }
                }
            }
        }
    }
    cout << tot;
    return 0;
}