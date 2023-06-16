#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, tot = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tot += a * b * c;
    }
    cout << tot / m + (tot % m != 0) << " " << (tot % m == 0 ? m : tot % m) << "\n";
    return 0;
}