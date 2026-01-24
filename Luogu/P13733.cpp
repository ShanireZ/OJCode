#include <algorithm>
#include <iostream>
using namespace std;
int n, k, a[300005];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int mx = 1, len = 1, lst = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == lst)
        {
            continue;
        }
        else if (a[i] - lst == 1)
        {
            len++, lst = a[i];
        }
        else
        {
            len = 1, lst = a[i];
        }
        mx = max(mx, len);
    }
    cout << (mx >= k ? "Yes" : "No") << endl;
    return 0;
}