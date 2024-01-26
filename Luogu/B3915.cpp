#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int now = 1, cnt = 0;
    while (now < n)
    {
        cnt++, now = a[now] + now;
    }
    cout << (now == n ? "Yes" : "No") << endl
         << cnt << endl;
    return 0;
}