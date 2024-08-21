#include <algorithm>
#include <iostream>
using namespace std;
int rec[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        rec[c][++rec[c][0]] = i;
    }
    for (int r = 1; r <= n / m; r++)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << rec[i][r] << '\n';
        }
    }
    return 0;
}