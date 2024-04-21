#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long l, r, k, jc = 1, mx = 0;
    cin >> l >> r >> k;
    for (int i = 1; i < l; i++)
    {
        jc = jc * i % k;
    }
    for (int i = l; i <= r; i++)
    {
        jc = jc * i % k;
        mx = max(mx, jc);
    }
    cout << mx << endl;
    return 0;
}