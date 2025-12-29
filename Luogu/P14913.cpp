#include <algorithm>
#include <iostream>
using namespace std;
int n, m, a[100005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int p, d;
        string s;
        cin >> p >> d >> s;
        if (s == "Completed")
        {
            a[p] = d;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}