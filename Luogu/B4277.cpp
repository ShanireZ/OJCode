#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int now = a[1], t = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            t++;
        }
        else if (t > n / 2)
        {
            ans = now;
            break;
        }
        else
        {
            now = a[i], t = 1;
        }
    }
    if (ans == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}