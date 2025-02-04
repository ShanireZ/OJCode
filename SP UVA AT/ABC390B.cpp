#include <algorithm>
#include <iostream>
using namespace std;
long long a[105];
int main()
{
    int n, ok = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 3; i <= n && ok; i++)
    {
        ok = (a[2] * a[i - 1] == a[1] * a[i]);
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}