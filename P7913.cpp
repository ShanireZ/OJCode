#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node
{
    int v, st, ed;
};
vector<Node> ns;
int main()
{
    int n;
    cin >> n;
    int pre = -1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == pre)
        {
            ns[ns.size() - 1].ed++;
        }
        else
        {
            Node tmp;
            tmp.v = x;
            tmp.st = i;
            tmp.ed = i;
            ns.push_back(tmp);
            pre = x;
        }
    }
    while (ns.size())
    {
        int pre = -1;
        for (int i = 0; i < ns.size(); i++)
        {
            if (pre == ns[i].v)
            {
                continue;
            }
            cout << ns[i].st << " ";
            ns[i].st++;
            pre = ns[i].v;
        }
        cout << endl;
        for (int i = ns.size() - 1; i >= 0; i--)
        {
            if (ns[i].st > ns[i].ed)
            {
                ns.erase(ns.begin() + i);
            }
        }
    }
    return 0;
}