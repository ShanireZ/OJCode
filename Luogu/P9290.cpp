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
            up[su.top().id] = i; // 后方第一个大于等于该数的位置
            su.pop();
        }
        su.emplace(Node{a[i], i});
        while (sd.size() && sd.top().v > a[i])
        {
            dw[sd.top().id] = i; // 后方第一个小于该数的位置
            sd.pop();
        }
        sd.emplace(Node{a[i], i});
    }
    int now = 1, res = 0;
    while (now <= n) // 分割点在第一个小于起点的位置前,最后一个大于等于起点的位置
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