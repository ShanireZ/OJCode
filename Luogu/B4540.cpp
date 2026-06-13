#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int id, b;
};
bool cmp(Node x, Node y)
{
    return x.b < y.b;
}
int t, n, m, a[10005];
vector<Node> ns[105];
int main()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        ns[x].push_back(Node{i, y}), a[i] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ns[i].begin(), ns[i].end(), cmp);
    }
    for (int i = 1; i <= t; i++)
    {
        int p;
        cin >> p;
        int x = a[i];
        cout << ns[x][p - 1].id << " ";
    }
    return 0;
}