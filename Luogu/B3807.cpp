#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long maxk = 0, p, r;
    cin >> p >> r;
    for (int i = 2; i <= n; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (p + r < a)
        {
            maxk = max(maxk, a - (p + r));
        }
        p = a, r = b;
    }
    cout << maxk << "\n";
    return 0;
}