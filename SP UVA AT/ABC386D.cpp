#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int x, y;
};
vector<Node> bk, wt, chk;
int n, m;
bool cmpx(Node a, Node b)
{
    return a.x < b.x;
}
bool cmpy(Node a, Node b)
{
    return a.y < b.y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        char opt;
        cin >> x >> y >> opt;
        opt == 'B' ? bk.emplace_back(Node{x, y}) : wt.emplace_back(Node{x, y});
    }
    if (bk.empty() || wt.empty())
    {
        cout << "Yes" << endl;
        return 0;
    }
    sort(bk.begin(), bk.end(), cmpx); // todo 根据每个黑点确认区域限制
    chk.emplace_back(bk[0]);
    for (int i = 1; i < (int)bk.size(); i++)
    {
        if (bk[i].x == chk.back().x)
        {
            chk.pop_back();
        }
        chk.emplace_back(bk[i]);
    }
    for (Node nd : wt) // todo 根据每个百点验证是否在限制区域外
    {
        auto it = lower_bound(chk.begin(), chk.end(), nd, cmpx);
        if (it != chk.end() && nd.y <= it->y)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    sort(bk.begin(), bk.end(), cmpy), chk.clear();
    chk.emplace_back(bk[0]);
    for (int i = 1; i < (int)bk.size(); i++)
    {
        if (bk[i].y == chk.back().y)
        {
            chk.pop_back();
        }
        chk.emplace_back(bk[i]);
    }
    for (Node nd : wt)
    {
        auto it = lower_bound(chk.begin(), chk.end(), nd, cmpy);
        if (it != chk.end() && nd.x <= it->x)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}