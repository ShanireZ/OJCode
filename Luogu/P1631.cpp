#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int v, id;
};
struct cmp
{
    bool operator()(Node n1, Node n2)
    {
        return n1.v > n2.v;
    }
};
priority_queue<Node, vector<Node>, cmp> c;
int a[100005], b[100005], p[100005];
//b中每一个元素和a中每一个元素相加，找出最小的N个
//a和b都是有序数列，所以a[1]+b[i]表示b中每一个和a中最小相加，其中肯定会有最小值
//如果a[1]+b[i]最小，那么输出该值，并且再将a[2]+b[i]放入优先队列，再以此类推
//p[i]存储b中第i个元素当前应该和a中哪个元素相加
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p[i] = 1;
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        Node tmp;
        tmp.id = i;
        tmp.v = a[p[i]] + b[i];
        p[i]++;
        c.push(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << c.top().v << " ";
        int id = c.top().id;
        c.pop();
        Node tmp;
        tmp.id = id;
        tmp.v = a[p[id]] + b[id];
        p[id]++;
        c.push(tmp);
    }
    return 0;
}