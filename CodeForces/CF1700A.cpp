#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        cout << (1 + m) * m / 2 + (m + n * m) * n / 2 - m << endl;
    }
    return 0;
}