#include <algorithm>
#include <iostream>
using namespace std;
int mx[105], my[105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> mx[i] >> my[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = 1; j <= n; j++)
        {
            x += mx[j], y += my[j];
        }
        cout << x << " " << y << endl;
    }
    return 0;
}