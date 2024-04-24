#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], p[100005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != p[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}