#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin >> k >> n;
    long long now = 1;
    while (n / now >= k)
    {
        n -= now * k;
        now *= 2;
    }
    if (n == 0)
    {
        cout << char('A' + k - 1) << endl;
    }
    else
    {
        cout << char('A' + (n - 1) / now) << endl;
    }
    return 0;
}