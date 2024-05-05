#include <iostream>
using namespace std;
int a[25], n, m, x, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        if (a[x] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}