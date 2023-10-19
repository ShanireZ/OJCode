#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> q;
vector<int> chs[105];
int ind[105], n, x;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        while (x)
        {
            chs[i].push_back(x), ind[x]++;
            cin >> x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        cout << now << " ";
        for (int nxt : chs[now])
        {
            ind[nxt]--;
            if (ind[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }
    return 0;
}