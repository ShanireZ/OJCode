#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    long long a, b, c, x;
    cin >> a >> b >> c;
    x = min(min(gcd(a, b), gcd(b, c)), gcd(c, a));
    cout << a * b * c / gcd(a, b) / gcd(b, c) / gcd(c, a) * x;
    return 0;
}