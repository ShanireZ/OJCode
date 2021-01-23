#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int a[100000][4];

int main()
{
    int n, i, x, y, num = -1;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }
    cin >> x >> y;
    for (i = 0; i < n; i++)
    {
        if (a[i][0] + a[i][2] >= x && x >= a[i][0] && a[i][1] + a[i][3] >= y && y >= a[i][1])
        {
            num = i + 1;
        }
    }
    cout << num;
    return 0;
}