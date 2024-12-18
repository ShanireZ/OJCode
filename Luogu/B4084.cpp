#include <algorithm>
#include <iostream>
using namespace std;
int vis[1005], n, p, res;
int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b == 1 && vis[a] == 0)
        {
            res++, vis[a] = 1;
        }
    }
    cout << res << endl;
    return 0;
}