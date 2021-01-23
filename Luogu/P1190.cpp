#include <iostream>
#include <algorithm>
using namespace std;
int water[105];
int wi[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> wi[i];
    }
    int cost = 0;
    if (n > m)
    {
        for (int i = 1; i <= m; i++)
        {
            water[i] = wi[i];
        }
        int pos = m + 1;
        while (pos <= n)
        {
            sort(water + 1, water + 1 + m);
            for (int i = 2; i <= m; i++)
            {
                water[i] -= water[1];
            }
            cost += water[1];
            water[1] = wi[pos++];
        }
    }
    int maxT = 0;
    for (int i = 1; i <= m; i++)
    {
        if (water[i] > maxT)
        {
            maxT = water[i];
        }
    }
    cout << maxT + cost;
    return 0;
}