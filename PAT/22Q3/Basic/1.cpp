#include <iostream>
using namespace std;
int main()
{
    long long a, n;
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x = a * a * a + 1;
        a = 0;
        while (x)
        {
            a += x % 10, x /= 10;
        }
    }
    cout << a;
    return 0;
}