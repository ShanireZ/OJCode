#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct Record
{
    string tn, n1, n2, n3;
    int tid, rk;
    bool operator<(const Record &oth) const
    {
        return (rk == oth.rk ? tid < oth.tid : rk < oth.rk);
    }
};
Record rec[10005];
map<string, bool> chk;
int n, m, t, k, pos, res[10005];
int main()
{
    cin >> n >> m >> t >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> rec[i].tn >> rec[i].n1 >> rec[i].n2 >> rec[i].n3 >> rec[i].tid >> rec[i].rk;
    }
    sort(rec + 1, rec + n + 1);
    for (int i = 1; i <= n && pos < k; i++)
    {
        if (chk[rec[i].n1] || chk[rec[i].n2] || chk[rec[i].n3])
        {
            continue;
        }
        res[++pos] = i;
        chk[rec[i].n1] = chk[rec[i].n2] = chk[rec[i].n3] = 1;
    }
    cout << pos << endl;
    for (int i = 1; i <= pos; i++)
    {
        cout << rec[res[i]].tn << " " << rec[res[i]].n1 << " " << rec[res[i]].n2 << " " << rec[res[i]].n3 << endl;
    }
    return 0;
}