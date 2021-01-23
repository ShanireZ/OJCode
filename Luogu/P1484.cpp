// 本题其实是在n个数中选出至多k个数，且两两不相邻，并使所选数的和最大
// 我们先进行小规模枚举
// k=1时，显然取n个数中取最大的即可（暂不考虑全负的情况）。设最大的数是a[i]
// k=2时，则有两种可能：1、另取一个与a[i]不相邻的a[j]。2、取a[i-1]和a[i+1]
// 我们可以发现：如果k=1时最优解为a[i]，那么我们便可以把a[i-1]和a[i+1]进行合并，因为它们要么同时被选，要么同时落选
// 因为如果只选其一的话，它们中的任意一个都比a[i]小）
// 而且，我们还注意到：当选了a[i-1]和a[i+1]时，获利便增加了a[i-1]+a[i+1]-a[i]
// 所以当a[i]被选时，我们就可以删去a[i-1]和a[i+1]，并把a[i]改成a[i-1]+a[i+1]-a[i]，重新找最大的
// 每次找的都是最大的数，我们便可以使用堆进行操作，直到堆中最大值小于0或取出k个数后停止

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
struct Node
{
    int usd, l, r; //l,r为点前节点的两侧节点 usd表示当前坑上是否还可种
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
    while (k > 0 && pq.top().v > 0) //必须有理可图才种树
    {
        QNode tmp = pq.top();
        pq.pop();
        int id = tmp.id;
        if (nodes[id].usd == 0)
        {
            k--;
            tot += tmp.v;
            tmp.v = -tmp.v;       //根据通项公式，需要减去自身
            if (nodes[id].l != 0) //如果当前左边还有坑
            {
                tmp.v += nodes[nodes[id].l].v;      //根据通项公式，需要加上两侧
                nodes[nodes[id].l].usd = 1;         //两侧坑已用
                nodes[id].l = nodes[nodes[id].l].l; //更新当前点的两侧，向外侧延伸
                nodes[nodes[id].l].r = id;          //更新新的两侧点的异向侧，类似于链表重新挂接
            }
            if (nodes[id].r != n + 1) //如果当前右边还有坑
            {
                tmp.v += nodes[nodes[id].r].v;
                nodes[nodes[id].r].usd = 1;
                nodes[id].r = nodes[nodes[id].r].r;
                nodes[nodes[id].r].l = id;
            }
            nodes[id].v = tmp.v; //更新当前点的权值
            pq.push(tmp);
        }
    }
    cout << tot;
    return 0;
}