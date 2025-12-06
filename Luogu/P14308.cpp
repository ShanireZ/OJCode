#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Area
{
    __int128 l, r, d, u, len, f;
};
vector<Area> as;
int T;
int main()
{
    as.push_back(Area{-1, 0, 0, 1, 1, 3});
    as.push_back(Area{-1, 0, -1, 0, 1, 0});
    while (as.size() < 100)
    {
        int pre = as.size() - 1;
        __int128 len = as[pre].len + as[pre - 1].len, f = (as[pre].f + 1) % 4;
        if (f == 0) // pre的左下向下行进len
        {
            __int128 d = as[pre].d - len, l = as[pre].l;
            as.push_back(Area{l, l + len, d, d + len, len, f});
        }
        else if (f == 1) // pre的右下向右行进len
        {
            __int128 d = as[pre].d, r = as[pre].r + len;
            as.push_back(Area{r - len, r, d, d + len, len, f});
        }
        else if (f == 2) // pre的右上向上行进len
        {
            __int128 u = as[pre].u + len, r = as[pre].r;
            as.push_back(Area{r - len, r, u - len, u, len, f});
        }
        else // pre的左上向左行进len
        {
            __int128 u = as[pre].u, l = as[pre].l - len;
            as.push_back(Area{l, l + len, u - len, u, len, f});
        }
    }
    cin >> T;
    while (T--)
    {
        long long x, y;
        cin >> x >> y;
        for (Area a : as)
        {
            if (x >= a.l && x <= a.r && y >= a.d && y <= a.u)
            {
                __int128 res = a.len;
                string s;
                while (res)
                {
                    s.push_back(res % 10 + '0');
                    res /= 10;
                }
                reverse(s.begin(), s.end());
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}