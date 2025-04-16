#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int x, y, k, vis[205];
int main()
{
    cin >> x >> y >> k;
    for (int i = 1; i <= x + y; i++)
    {
        q.emplace(i);
    }
    while ((int)q.size() != x)
    {
        int t = 1;
        while (t != k)
        {
            int x = q.front();
            q.pop();
            q.emplace(x), t++;
        }
        int x = q.front();
        q.pop(), vis[x] = 1;
    }
    for (int i = 1; i <= x + y; i++)
    {
        if (vis[i] == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}