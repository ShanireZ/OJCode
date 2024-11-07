#include <algorithm>
#include <iostream>
using namespace std;
int c[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;
        a >= 0 ? c[n] += a : c[1] += a;
    }
    cout << c[n] << endl;
    return 0;
}