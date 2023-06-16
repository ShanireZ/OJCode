#include <algorithm>
#include <iostream>
using namespace std;
int nxt[2005], ok[2005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m, x;
        cin >> m;
        if (m == 0)
        {
            cin >> x;
            nxt[i] = x;
            if (x != -1)
            {
                ok[x] = 1;
            }
        }
        else
        {
            int fa = i;
            while (m--)
            {
                cin >> x;
                nxt[fa] = x, ok[x] = 1;
                fa = x;
            }
        }
    }
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ok[i] == 0)
        {
            now = i;
            break;
        }
    }
    while (now != -1)
    {
        cout << now << " ";
        now = nxt[now];
    }
    return 0;
}