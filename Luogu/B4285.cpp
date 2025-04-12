#include <algorithm>
#include <iostream>
using namespace std;
int w[505], h[505], n, k, mxw, mxh;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> h[i];
        mxw = max(mxw, w[i]);
        mxh = max(mxh, h[i]);
    }
    cin >> k;
    for (int l = min(mxw, mxh); l >= 1; l--)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += (w[i] / l) * (h[i] / l);
        }
        if (cnt >= k)
        {
            cout << l << endl;
            break;
        }
    }
    return 0;
}