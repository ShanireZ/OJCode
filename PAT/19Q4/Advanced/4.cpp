#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int all[35];
struct Node
{
    int L, R, pos;
};
queue<Node> p;
int find_min(int start, int end)
{
    int min_pos = start;
    for (int i = start; i <= end; i++)
    {
        if (all[i] < all[min_pos])
        {
            min_pos = i;
        }
    }
    return min_pos;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    Node node;
    node.L = 1;
    node.R = n;
    node.pos = find_min(1, n);
    p.push(node);
    while (p.size() != 0)
    {
        Node mid = p.front();
        if (mid.pos - 1 >= mid.L)
        {
            Node tmp;
            tmp.pos = find_min(mid.L, mid.pos - 1);
            tmp.L = mid.L;
            tmp.R = mid.pos - 1;
            p.push(tmp);
        }
        if (mid.pos + 1 <= mid.R)
        {
            Node tmp;
            tmp.pos = find_min(mid.pos + 1, mid.R);
            tmp.L = mid.pos + 1;
            tmp.R = mid.R;
            p.push(tmp);
        }
        p.pop();
        cout << all[mid.pos];
        if (p.size() != 0)
        {
            cout << " ";
        }
    }
    return 0;
}