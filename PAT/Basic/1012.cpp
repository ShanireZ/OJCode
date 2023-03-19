#include <iomanip>
#include <iostream>
using namespace std;
int t[10], vis[10];
int main()
{
    int n, p2 = 1, p4 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % 5 == 0)
        {
            if (x % 2 == 0)
            {
                t[1] += x, vis[1] = 1;
            }
        }
        else if (x % 5 == 1)
        {
            t[2] = (p2 % 2 == 1 ? t[2] + x : t[2] - x), p2++, vis[2] = 1;
        }
        else if (x % 5 == 2)
        {
            t[3]++, vis[3] = 1;
        }
        else if (x % 5 == 3)
        {
            t[4] += x, p4++, vis[4] = 1;
        }
        else
        {
            t[5] = max(t[5], x), vis[5] = 1;
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        if (vis[i] == 0)
        {
            cout << "N";
        }
        else if (i != 4)
        {
            cout << t[i];
        }
        else
        {
            cout << fixed << setprecision(1) << t[4] * 1.0 / p4;
        }
        if (i != 5)
        {
            cout << " ";
        }
    }
    return 0;
}