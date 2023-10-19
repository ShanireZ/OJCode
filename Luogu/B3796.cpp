#include <iostream>
using namespace std;
int main()
{
    int n, m, cost = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (m >= x)
        {
            m -= x, cost += x;
        }
    }
    m = cost * 0.88;
    cout << cost - m << endl;
    return 0;
}