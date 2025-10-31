#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int id;
    double s;
    bool operator<(const Node &oth) const
    {
        return s > oth.s;
    }
};
Node ns[105];
int n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].id >> ns[i].s;
    }
    sort(ns + 1, ns + 1 + n);
    cout << ns[k].id << " " << ns[k].s << endl;
    return 0;
}