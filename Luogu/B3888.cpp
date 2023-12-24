#include <algorithm>
#include <iostream>
using namespace std;
int prim[10005], vis[10005], pos, n;
void init()
{
    for (int i = 2; i <= 10000; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
        }
        for (int j = 1; j <= pos && prim[j] * i <= 10000; j++)
        {
            vis[prim[j] * i] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char now = 'A' + i - 1;
        for (int j = 1, p = 1; j <= i * i; p++)
        {
            if (vis[now + p] == 1)
            {
                cout << " ";
            }
            else
            {
                cout << now;
                now = (now + 1 > 'Z' ? 'A' : now + 1), j++;
            }
        }
        cout << endl;
    }
    return 0;
}