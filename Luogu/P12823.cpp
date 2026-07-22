#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int pos, mx, cx;
};
int n, fa, v[200005];
vector<int> to[200005];
queue<int> pre, now;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa;
        to[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    Node ans = Node{1, v[1], 0};
    pre.push(1);
    while (pre.size())
    {
        int pos = ans.pos, mx = ans.mx, cx = ans.cx;
        while (pre.size())
        {
            fa = pre.front(), pre.pop();
            for (int x : to[fa])
            {
                now.push(x);
                int val = v[x] + (fa == ans.pos ? ans.cx : ans.mx);
                if (val > mx)
                {
                    cx = mx, mx = val, pos = x;
                }
                else if (val > cx)
                {
                    cx = val;
                }
            }
        }
        ans = Node{pos, mx, cx};
        pre = now, now = queue<int>();
    }
    cout << ans.mx << endl;
    return 0;
}