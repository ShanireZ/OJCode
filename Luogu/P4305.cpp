#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int num, id;
};
Node ns[50005];
bool cmp(Node a, Node b)
{
    if (a.num == b.num)
    {
        return a.id < b.id;
    }
    return a.num < b.num;
}
bool cmp_final(Node a, Node b)
{
    return a.id < b.id;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            cin >> ns[j].num;
            ns[j].id = j;
        }
        sort(ns + 1, ns + 1 + n, cmp);
        for (int j = 2; j <= n; j++)
        {
            if (ns[j].num == ns[j - 1].num)
            {
                ns[j].id = 50009;
            }
        }
        sort(ns + 1, ns + 1 + n, cmp_final);
        for (int j = 1; j <= n && ns[j].id != 50009; j++)
        {
            cout << ns[j].num << " ";
        }
        cout << endl;
    }
    return 0;
}