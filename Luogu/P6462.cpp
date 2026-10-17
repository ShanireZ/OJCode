#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long h, x, y;
        cin >> h >> x >> y;
        //! 如果塔沒攻擊力但玩家有 或者 玩家攻擊力高於怪物生命
        if (x == 0 && y != 0 || y >= h)
        {
            cout << "Yes" << endl;
            continue;
        }
        //! 如果玩家沒攻擊力 或者 塔的攻擊力高於怪物生命且玩家攻擊力不夠秒殺
        if (y == 0 || x >= h && y < h)
        {
            cout << "No" << endl;
            continue;
        }
        int times = h / x; //! 可以允許塔打幾次
        if (h % x == 0)    //! 如果剛好能打完 那麼讓塔少打一次
        {
            times--;
            h = x;
        }
        else
        {
            h = h % x; //! 塔打完times次怪物還剩多少血
        }
        if (y * (times + 1) >= h) //! 玩家能比塔多打一次
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}