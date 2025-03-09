#include <algorithm>
#include <iostream>
using namespace std;
int cd[1005], ls[1005], n, k, p;
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
    {
        cd[i] = i;
    }
    while (k--)
    {
        for (int i = 1, p1 = 1, p2 = n / 2 + 1; i <= n; i++)
        {
            ls[i] = (i % 2 ? cd[p1++] : cd[p2++]);
        }
        for (int i = 1; i <= n; i++)
        {
            cd[i] = ls[i];
        }
    }
    cout << cd[p] << endl;
    return 0;
}