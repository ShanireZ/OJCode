#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, l, r;
    cin >> n >> l >> r;
    long long s = r / n * n, ex = 0, v = r / n;
    if (s < l)
    {
        ex = l - s;
    }
    else if (s > r)
    {
        ex = r - s;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ex == 0)
        {
            cout << v << " ";
        }
        else
        {
            int add = (ex > 0 ? min(1000000 - v, ex) : max(-1000000 - v, ex));
            ex -= add;
            cout << v + add << " ";
        }
    }
    return 0;
}