#include <iostream>
using namespace std;
int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    long long day = n / (a * 5 + b * 2) * 7;
    n %= a * 5 + b * 2;
    for (int i = 1; i <= 5 && n > 0; i++, day++)
    {
        n -= a;
    }
    for (int i = 1; i <= 2 && n > 0; i++, day++)
    {
        n -= b;
    }
    cout << day << endl;
    return 0;
}