#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct Rec
{
    string id, st, ed;
};
Rec rs[100005];
bool cmpst(Rec a, Rec b)
{
    return a.st < b.st;
}
bool cmped(Rec a, Rec b)
{
    return a.ed > b.ed;
}
int main() // 来的最早和走的最晚的ID
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> rs[i].id >> rs[i].st >> rs[i].ed;
    }
    sort(rs + 1, rs + 1 + m, cmpst);
    cout << rs[1].id << " ";
    sort(rs + 1, rs + 1 + m, cmped);
    cout << rs[1].id;
    return 0;
}