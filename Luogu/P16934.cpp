#include <algorithm>
#include <iostream>
using namespace std;
#define M 200005
int n, k, mx, mn, a[M], qzmx[M], qzmn[M], hzmx[M], hzmn[M];
int main()
{
    cin >> n >> k;
    mn = qzmn[0] = hzmn[n + 1] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        qzmx[i] = max(qzmx[i - 1], a[i]);
        qzmn[i] = min(qzmn[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        hzmx[i] = max(hzmx[i + 1], a[i]);
        hzmn[i] = min(hzmn[i + 1], a[i]);
    }
    for (int l = 1, r = k; r <= n; l++, r++)
    {
        int nowmx = max(qzmx[l - 1], hzmx[r + 1]);
        int nowmn = min(qzmn[l - 1], hzmn[r + 1]);
        mx = max(mx, nowmx - nowmn);
        mn = min(mn, nowmx - nowmn);
    }
    cout << mx << " " << mn << endl;
    return 0;
}