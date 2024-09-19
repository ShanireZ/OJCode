#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long tot = 1;
    for (int i = 1; i <= n; i++)
    {
        tot *= i;
    }
    cout << (tot % (n + 1) ? "NO" : "YES") << endl;
    return 0;
}