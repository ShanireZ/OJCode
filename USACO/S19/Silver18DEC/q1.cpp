#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cow[100005];
int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    sort(cow + 1, cow + n + 1);
    int left = 0, right = cow[n];
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int car = 0, cur = 0;
        int start = 0;
        for (int i = 1; i <= n;)
        {
            start = i;
            while (cow[start] + mid >= cow[i] && cur < c && i <= n)
            {
                cur++;
                i++;
            }
            car++;
            cur = 0;
        }
        if (car <= m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}