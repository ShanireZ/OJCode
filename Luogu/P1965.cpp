#include <iostream>
using namespace std;
int n, m, k, x;
int main()
{
    cin >> n >> m >> k >> x;
    m %= n, x %= n;
    long long base = 10, now = 1;
    while (k)
    {
        if (k & 1)
        {
            now = now * base % n;
        }
        k /= 2, base = base * base % n;
    }
    cout << (now * m % n + x) % n << endl;
    return 0;
}