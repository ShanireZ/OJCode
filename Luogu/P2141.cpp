#include <iostream>
using namespace std;
int nums[105], vis[20005];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        vis[nums[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ans = nums[i] + nums[j];
            if (vis[ans] == 1)
            {
                cnt++;
                vis[ans] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}