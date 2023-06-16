#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        tot += 0ll + a + x;
    }
    cout << tot << "\n";
    return 0;
}