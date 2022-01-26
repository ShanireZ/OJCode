#include <iostream>
#include <algorithm>
using namespace std;
int cow[100005];
int main()
{
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
        int mid = (left + right) / 2, car = 0;
        for (int i = 1; i <= n; car++)
        {
            int start = i, cnt = 0;
            while (cow[start] + mid >= cow[i] && cnt < c && i <= n)
            {
                cnt++, i++;
            }
        }
        (car <= m) ? right = mid - 1 : left = mid + 1;
    }
    cout << left;
    return 0;
}