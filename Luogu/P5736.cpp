#include <cmath>
#include <iostream>
using namespace std;
int vis[100005], n, num;
int main()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (vis[i] == 0)
        {
            for (int j = 2; i * j <= 100000; j++)
            {
                vis[i * j] = 1;
            }
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if (vis[num] == 0)
        {
            cout << num << " ";
        }
    }
    return 0;
}