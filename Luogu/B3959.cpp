#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= ans)
        {
            ans++;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}