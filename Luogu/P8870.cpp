#include <algorithm>
#include <iostream>
using namespace std;
int a[200005], b[200005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
    {
        cin >> a[i];
    }
    for (int i = m; i >= 1; i--)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= max(n, m) + 1; i++)
    {
        a[i] += b[i];
        int ex = a[i] / (i + 1);
        a[i] %= i + 1, a[i + 1] += ex;
    }
    if (a[max(n, m) + 1])
    {
        cout << a[max(n, m) + 1] << " ";
    }
    for (int i = max(n, m); i >= 1; i--)
    {
        cout << a[i] << " ";
    }
    return 0;
}