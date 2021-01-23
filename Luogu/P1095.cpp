#include <iostream>
#include <algorithm>
using namespace std;
int dis[300005];
int main()
{
    int m, s, t;
    cin >> m >> s >> t;
    for (int i = 1; i <= t; i++)
    {
        if (m >= 10)
        {
            dis[i] = dis[i - 1] + 60;
            m -= 10;
        }
        else
        {
            dis[i] = dis[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; i++)
    {
        dis[i] = max(dis[i], dis[i - 1] + 17);
        if (dis[i] >= s)
        {
            cout << "Yes" << endl;
            cout << i;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << dis[t];
    return 0;
}