#include <iostream>
using namespace std;
int main()
{
    long long x, n, tot = 1;
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        tot += tot * x;
    }
    cout << tot;
    return 0;
}