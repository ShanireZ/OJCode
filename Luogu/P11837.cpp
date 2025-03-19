#include <algorithm>
#include <iostream>
using namespace std;
int n, a[200005], c[200005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    cout << c[0] << endl;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (c[i - 1] == 0);
        cout << max(res, c[i]) << endl;
    }
    return 0;
}