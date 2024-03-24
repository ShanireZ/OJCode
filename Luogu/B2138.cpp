#include <algorithm>
#include <iostream>
using namespace std;
int vis[5005], prim[5005], pos, a, b;
int main()
{
    cin >> a >> b;
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= b; i++)
    {
        if (vis[i] == 0)
        {
            prim[++pos] = i;
            for (int j = i + i; j <= b; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        for (int j = pos; j >= 1; j--)
        {
            if (i % prim[j] == 0)
            {
                if (i > a)
                {
                    cout << ",";
                }
                cout << prim[j];
                break;
            }
        }
    }
    return 0;
}