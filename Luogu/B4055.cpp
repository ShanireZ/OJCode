#include <algorithm>
#include <iostream>
using namespace std;
int a[1005];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int trig = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] <= a[j])
            {
                trig = 0;
                break;
            }
        }
        ans += trig;
    }
    cout << ans << endl;
    return 0;
}