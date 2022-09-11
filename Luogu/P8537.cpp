#include <iostream>
using namespace std;
int a[500005], b[500005];
int main()
{
    int n, tota = 0, totb = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tota += (a[i] != x), totb += (b[i] != x);
    }
    cout << min(tota, totb) << endl;
    return 0;
}