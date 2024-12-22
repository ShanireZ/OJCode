#include <algorithm>
#include <iostream>
using namespace std;
int x[505], n, w;
int main()
{
    cin >> w >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    x[n + 1] = 2e9 + 3;
    for (int i = 1; i <= n + 1; i++)
    {
        if (w >= x[i])
        {
            w -= x[i];
        }
        else
        {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}