#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n + n; i++)
    {
        long long x;
        cin >> x;
        tot += x;
    }
    cout << (tot + 1) / 2 << endl;
    return 0;
}