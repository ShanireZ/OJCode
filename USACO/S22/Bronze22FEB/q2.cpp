#include <iostream>
using namespace std;
int a[100005], b[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b[i] = a[x];
    }
    int cnt = 0, minx = b[n];
    for (int i = n - 1; i >= 1; i--)
    {
        if (b[i] > minx)
        {
            cnt++;
        }
        minx = min(minx, b[i]);
    }
    cout << cnt << endl;
    return 0;
}