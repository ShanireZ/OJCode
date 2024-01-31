#include <algorithm>
#include <iostream>
using namespace std;
bool check(long long x)
{
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long long n, k;
    cin >> n >> k;
    if (check(k + 1) && 2 * (k + 1) > n + 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    return 0;
}