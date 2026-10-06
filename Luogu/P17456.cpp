#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int v, s;
};
vector<Node> ns1, ns9;
int n, t, tot1, tot9;
double ans;
bool cmps9(Node a, Node b)
{
    return a.s < b.s;
}
bool cmps1(Node a, Node b)
{
    return a.s > b.s;
}
int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int v, s;
        cin >> v >> s;
        if (s < t)
        {
            ns1.push_back(Node{v, s});
            tot1 += (t - s) * v;
        }
        else if (s == t)
        {
            ans += v;
        }
        else
        {
            ns9.push_back(Node{v, s});
            tot9 += (s - t) * v;
        }
    }
    if (tot1 == tot9)
    {
        for (Node now : ns1)
        {
            ans += now.v;
        }
        for (Node now : ns9)
        {
            ans += now.v;
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    else if (tot1 > tot9)
    {
        for (Node now : ns9)
        {
            ans += now.v;
        }
        sort(ns1.begin(), ns1.end(), cmps1), tot1 = 0;
        for (Node now : ns1)
        {
            int d = (t - now.s) * now.v;
            if (tot1 + d < tot9)
            {
                tot1 += d, ans += now.v;
            }
            else 
            {
                ans += 1.0 * (tot9 - tot1) / (t - now.s);
                break;
            }
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    else
    {
        for (Node now : ns1)
        {
            ans += now.v;
        }
        sort(ns9.begin(), ns9.end(), cmps9), tot9 = 0;
        for (Node now : ns9)
        {
            int d = (now.s - t) * now.v;
            if (tot9 + d < tot1)
            {
                tot9 += d, ans += now.v;
            }
            else
            {
                ans += 1.0 * (tot1 - tot9) / (now.s - t);
                break;
            }
        }
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}