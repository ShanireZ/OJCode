#include <algorithm>
#include <iostream>
using namespace std;
int t[25][25];
int main()
{
    int n;
    cin >> n;
    int h = 1, l = n / 2 + 1;
    t[h][l] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        int a = h, b = l;
        a = (a == 1 ? n : a - 1);
        b = (b == n ? 1 : b + 1);
        if (t[a][b] == 0)
        {
            t[a][b] = i;
            h = a, l = b;
            continue;
        }
        h = (h == n ? 1 : h + 1);
        t[h][l] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}