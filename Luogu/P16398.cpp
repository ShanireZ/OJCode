#include <algorithm>
#include <iostream>
using namespace std;
char dir;
int T, xs, ys, xt, yt;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> xs >> ys >> dir >> xt >> yt;
        int x = xt - xs, y = yt - ys, c = 0;
        if (dir == 'N')
        {
            if (x > 0)
            {
                c = 1;
            }
            if (y < 0)
            {
                c = 2;
            }
            if (x < 0)
            {
                c = 3;
            }
        }
        else if (dir == 'E')
        {
            if (y < 0)
            {
                c = 1;
            }
            if (x < 0)
            {
                c = 2;
            }
            if (y > 0)
            {
                c = 3;
            }
        }
        else if (dir == 'S')
        {
            if (x < 0)
            {
                c = 1;
            }
            if (y > 0)
            {
                c = 2;
            }
            if (x > 0)
            {
                c = 3;
            }
        }
        else
        {
            if (y > 0)
            {
                c = 1;
            }
            if (x > 0)
            {
                c = 2;
            }
            if (y < 0)
            {
                c = 3;
            }
        }
        cout << c << endl;
    }
    return 0;
}