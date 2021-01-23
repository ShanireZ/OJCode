#include <iostream>
#include <algorithm>
using namespace std;
int cow[100005];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    sort(cow + 1, cow + 1 + n, cmp);
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        if (cow[i] < i - 1)
        {
            ans = i - 1;
            break;
        }
    }
    cout << ans;
    return 0;
}