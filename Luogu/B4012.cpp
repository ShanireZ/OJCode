#include <algorithm>
#include <iostream>
using namespace std;
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            int r;
            cin >> r;
            cnt += (r == k);
        }
        tot += (cnt >= n / 2.0);
    }
    if (tot >= m / 2.0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}