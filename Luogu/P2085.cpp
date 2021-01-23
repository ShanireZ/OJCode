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
int a[10005][3], p[10005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        p[i] = 1;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for (int i = 1; i <= n; i++)
    {
        Node tmp;
        tmp.id = i;
        tmp.v = a[i][0] * p[i] * p[i] + a[i][1] * p[i] + a[i][2];
        p[i]++;
        c.push(tmp);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << c.top().v << " ";
        int id = c.top().id;
        c.pop();
        Node tmp;
        tmp.id = id;
        tmp.v = a[id][0] * p[id] * p[id] + a[id][1] * p[id] + a[id][2];
        p[id]++;
        c.push(tmp);
    }
    return 0;
}