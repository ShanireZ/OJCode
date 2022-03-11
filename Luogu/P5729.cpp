#include <iostream>
using namespace std;
int cube[25][25][25]; // 0表示还存在没切 1表示已经切掉了不存在
int main()
{
    int w, x, h;
    cin >> w >> x >> h;
    int q;
    cin >> q;
    int tot = w * x * h;
    for (int i = 1; i <= q; i++)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int a = x1; a <= x2; a++)
        {
            for (int b = y1; b <= y2; b++)
            {
                for (int c = z1; c <= z2; c++)
                {
                    if (cube[a][b][c] == 0)
                    {
                        cube[a][b][c] = 1;
                        tot--;
                    }
                }
            }
        }
    }
    cout << tot << endl;
    return 0;
}