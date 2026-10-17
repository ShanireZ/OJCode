// 本題其實是在n個數中選出至多k個數，且兩兩不相鄰，並使所選數的和最大
// 我們先進行小規模枚舉
// k=1時，顯然取n個數中取最大的即可（暫不考慮全負的情況）。設最大的數是a[i]
// k=2時，則有兩種可能：1、另取一個與a[i]不相鄰的a[j]。2、取a[i-1]和a[i+1]
// 我們可以發現：如果k=1時最優解為a[i]，那麼我們便可以把a[i-1]和a[i+1]進行合併，因為它們要麼同時被選，要麼同時落選
// 因為如果只選其一的話，它們中的任意一個都比a[i]小）
// 而且，我們還注意到：當選了a[i-1]和a[i+1]時，獲利便增加了a[i-1]+a[i+1]-a[i]
// 所以當a[i]被選時，我們就可以刪去a[i-1]和a[i+1]，並把a[i]改成a[i-1]+a[i+1]-a[i]，重新找最大的
// 每次找的都是最大的數，我們便可以使用堆進行操作，直到堆中最大值小於0或取出k個數後停止

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
struct Node
{
    int usd, l, r; //l,r為點前節點的兩側節點 usd表示當前坑上是否還可種
    long long v;
};
Node nodes[500005];
struct QNode
{
    int id;
    long long v;
};
struct cmp
{
    bool operator()(QNode a, QNode b)
    {
        return a.v < b.v;
    }
};
priority_queue<QNode, vector<QNode>, cmp> pq;
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].v;
        nodes[i].l = i - 1;
        nodes[i].r = i + 1;
        QNode tmp;
        tmp.v = nodes[i].v;
        tmp.id = i;
        pq.push(tmp);
    }
    long long tot = 0;
    while (k > 0 && pq.top().v > 0) //必須有理可圖才種樹
    {
        QNode tmp = pq.top();
        pq.pop();
        int id = tmp.id;
        if (nodes[id].usd == 0)
        {
            k--;
            tot += tmp.v;
            tmp.v = -tmp.v;       //根據通項公式，需要減去自身
            if (nodes[id].l != 0) //如果當前左邊還有坑
            {
                tmp.v += nodes[nodes[id].l].v;      //根據通項公式，需要加上兩側
                nodes[nodes[id].l].usd = 1;         //兩側坑已用
                nodes[id].l = nodes[nodes[id].l].l; //更新當前點的兩側，向外側延伸
                nodes[nodes[id].l].r = id;          //更新新的兩側點的異向側，類似於鏈表重新掛接
            }
            if (nodes[id].r != n + 1) //如果當前右邊還有坑
            {
                tmp.v += nodes[nodes[id].r].v;
                nodes[nodes[id].r].usd = 1;
                nodes[id].r = nodes[nodes[id].r].r;
                nodes[nodes[id].r].l = id;
            }
            nodes[id].v = tmp.v; //更新當前點的權值
            pq.push(tmp);
        }
    }
    cout << tot;
    return 0;
}