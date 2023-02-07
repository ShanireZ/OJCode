#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        int x = m, cnt = 0;
        while (x)
        {
            x /= 2, cnt++;
        }
        if ((k > m && n == 1) || (k > pow(2, cnt) - 1))
        {
            cout << "-1\n";
            continue;
        }
        if (m >= k)
        {
            cout << k << " ";
        }
        else
        {
            cout << m << " " << (k ^ m) << " ";
        }
        for (int i = (m >= k) ? 2 : 3; i <= n; i++)
        {
            cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}