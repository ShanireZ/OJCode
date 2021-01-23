#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, t = 0;
    cin >> n;
    long long a = 1, b = 0;
    while (t != n)
    {
        long long c = a + b;
        a = b;
        b = c;
        t++;
    }
    cout << b << ".00";
    return 0;
}