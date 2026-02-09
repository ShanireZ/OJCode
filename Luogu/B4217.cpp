#include <algorithm>
#include <iostream>
using namespace std;
int n, now, h[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        if (h[i] == 0)
        {
            h[i] = ++now;
        }
        else if (h[i] <= now)
        {
            now = 1e9 + 7;
            break;
        }
        else
        {
            now = h[i];
        }
    }
    if (now > 1e9)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << h[i] << " ";
    }
    cout << endl;
    return 0;
}