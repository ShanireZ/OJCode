#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, maxp = 0, ans2 = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[j];
            if (a[j] > a[maxp])
            {
                maxp = j;
                ans2 = cnt;
            }
            cnt += (a[j] != 0);
        }
        cout << maxp << " " << ans2 << endl;
    }
    return 0;
}