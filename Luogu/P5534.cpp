#include <iostream>
using namespace std;
int main()
{
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;
    long long d = a2 - a1;
    a2 = a1 + (n - 1) * d;
    cout << (a1 + a2) * n / 2;
    return 0;
}