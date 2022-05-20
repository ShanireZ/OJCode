#include <cmath>
#include <iostream>
using namespace std;
struct Node
{
    int t, x, y;
};
Node ns[205];
long long nums[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].t >> ns[i].x >> ns[i].y;
    }
    for (int i = m; i >= 1; i--)
    {
        int x = ns[i].x, y = ns[i].y;
        if (ns[i].t == 1)
        {
            (x == y) ? nums[x] /= 2 : nums[x] -= nums[y];
        }
        else
        {
            (x == y) ? nums[x] = sqrt(nums[x]) : nums[x] /= nums[y];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}