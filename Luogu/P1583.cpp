#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Fan
{
    int id, C, total;
};

bool cmp_total(Fan a, Fan b)
{
    if (a.total == b.total)
    {
        return a.id < b.id;
    }
    return a.total > b.total;
}

Fan fans[20001];
int es[11];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 10; i++)
    {
        cin >> es[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> fans[i].total;
        fans[i].id = i;
    }
    sort(fans + 1, fans + n + 1, cmp_total);
    for (int i = 1; i <= n; i++)
    {
        fans[i].C = (i - 1) % 10 + 1;
        fans[i].total += es[fans[i].C];
    }
    sort(fans + 1, fans + n + 1, cmp_total);
    for (int i = 1; i <= k; i++)
    {
        cout << fans[i].id << " ";
    }
    return 0;
}