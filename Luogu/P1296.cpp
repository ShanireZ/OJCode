#include <iostream>
#include <algorithm>
using namespace std;
int cow[1000005];
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    sort(cow + 1, cow + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (cow[j] - cow[i] <= d)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}