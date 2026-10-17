#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int v, id;
};
stack<Node> su, sd;
int up[300005], dw[300005], a[300005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dw[i] = n + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        while (su.size() && su.top().v <= a[i])
        {
            up[su.top().id] = i; // 後方第一個大於等於該數的位置
            su.pop();
        }
        su.emplace(Node{a[i], i});
        while (sd.size() && sd.top().v > a[i])
        {
            dw[sd.top().id] = i; // 後方第一個小於該數的位置
            sd.pop();
        }
        sd.emplace(Node{a[i], i});
    }
    int now = 1, res = 0;
    while (now <= n) // 分割點在第一個小於起點的位置前,最後一個大於等於起點的位置
    {
        if (up[now] != 0)
        {
            int lmt = dw[now];
            while (up[now] && up[now] < lmt)
            {
                now = up[now];
            }
        }
        res++, now++;
    }
    cout << res << endl;
    return 0;
}