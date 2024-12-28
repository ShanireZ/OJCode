#include <algorithm>
#include <iostream>
using namespace std;
int t[200005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        t[l]++, t[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        t[i] = t[i - 1] + t[i];
        cout << (t[i] % 2 ? 1 : 0);
    }
    return 0;
}