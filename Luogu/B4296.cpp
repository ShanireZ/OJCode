#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int t[105], jmp[105], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> jmp[i];
    }
    fill(t + 1, t + 1 + n, n);
    q.emplace(1), t[1] = 0;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 1; i <= jmp[now] && now + i <= n; i++)
        {
            if (t[now] + 1 < t[now + i])
            {
                t[now + i] = t[now] + 1;
                q.emplace(now + i);
            }
        }
    }
    cout << t[n] << endl;
    return 0;
}