#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, mx = -1e15, mn = 1e15;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        mx = max(mx, x), mn = min(mn, x);
    }
    cout << mx + mn << endl;
    return 0;
}