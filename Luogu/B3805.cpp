#include <algorithm>
#include <iostream>
using namespace std;
int vis[1000005];
int main()
{
    int n, cnt = 0;
    cin >> n;
    while (n--)
    {
        int s;
        cin >> s;
        if (vis[s] == 0)
        {
            vis[s] = 1, cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}