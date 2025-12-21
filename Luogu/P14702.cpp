#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n, w, ans;
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > w)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    sort(a + 1, a + n + 1);
    if (a[1] + a[2] > w)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        if (a[1] + a[i] <= w)
        {
            ans += 2;
        }
        else
        {
            ans += 4;
        }
    }
    cout << ans + 1 << endl; // a[1]a[2]过河+1次
    return 0;
}