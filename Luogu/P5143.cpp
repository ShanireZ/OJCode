#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
struct Node
{
    int x, y, z;
};
Node ns[50005];
bool cmp(Node a, Node b)
{
    return a.z < b.z;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ns[i].x >> ns[i].y >> ns[i].z;
    }
    sort(ns, ns + n, cmp);
    double tot = 0;
    Node st = ns[0];
    for (int i = 1; i < n; i++)
    {
        tot += sqrt(pow(ns[i].x - st.x, 2) + pow(ns[i].y - st.y, 2) + pow(ns[i].z - st.z, 2));
        st.x = ns[i].x;
        st.y = ns[i].y;
        st.z = ns[i].z;
    }
    cout << fixed << setprecision(3) << tot;
    return 0;
}