#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, c = 0, s = 0;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        c += i * 3 - (i - 1), s += i * i;
    }
    cout << c + n << endl;
    cout << s << endl;
    return 0;
}