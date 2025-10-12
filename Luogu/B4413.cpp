#include <algorithm>
#include <iostream>
using namespace std;
int n, cnt, a[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (a[n])
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
            {
                a[n] -= a[i];
                break;
            }
        }
        cnt++, sort(a + 1, a + n + 1);
    }
    cout << cnt << endl;
    return 0;
}