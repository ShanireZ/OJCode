#include <algorithm>
#include <iostream>
using namespace std;
int n, vis[15];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    if (vis[2] == 1)
    {
        cout << "2" << endl;
    }
    else if (vis[3] == 1)
    {
        cout << "3" << endl;
    }
    else if (vis[5] == 1)
    {
        cout << "5" << endl;
    }
    else if (vis[7] == 1)
    {
        cout << "7" << endl;
    }
    else if (vis[1] == 1)
    {
        cout << "11" << endl;
    }
    else if (vis[8] == 1 && vis[9] == 1)
    {
        cout << "89" << endl;
    }
    else if (vis[4] == 1 && vis[9] == 1)
    {
        cout << (vis[0] == 1 ? "409" : "449") << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}