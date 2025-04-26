#include <algorithm>
#include <iostream>
using namespace std;
int h[5000005], ans[5000005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    sort(h + 1, h + n + 1);
    for (int i = 1, l = 1, r = n; i <= n; i++)
    {
        i % 2 == 1 ? ans[l++] = h[i] : ans[r--] = h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}