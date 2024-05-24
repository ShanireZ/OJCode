#include <algorithm>
#include <iostream>
using namespace std;
int xl[1000005][2];
int main()
{
    int n, p, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> xl[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> xl[i][1];
    }
    cin >> p >> q;
    for (int i = 0; i <= n; i++)
    {
        if ((q + i <= n && xl[q + i][p] == 0) || (q - i >= 1 && xl[q - i][p] == 0))
        {
            cout << p << " " << i << endl;
            return 0;
        }
        if ((q + i <= n && xl[q + i][1 - p] == 0) || (q - i >= 1 && xl[q - i][1 - p] == 0))
        {
            cout << 1 - p << " " << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}