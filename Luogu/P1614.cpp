#include <iostream>
#include <algorithm>
using namespace std;
int all[3005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    int c = 0;
    for (int i = 1; i <= m; i++)
    {
        c += all[i];
    }
    int minc = c;
    for (int i = 2; i <= n - m + 1; i++)
    {
        c = c - all[i - 1] + all[i + m - 1];
        minc = min(c, minc);
    }
    cout << minc;
    return 0;
}