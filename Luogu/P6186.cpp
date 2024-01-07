#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long a[200005], ta[200005], nx[200005], tnx[200005], cnx[200005], n, m, sz;
vector<long long> all;
long long lowbit(long long x)
{
    return x & -x;
}
void edit(long long p) // 维护每个数出现的次数
{
    while (p <= sz)
    {
        ta[p]++, p += lowbit(p);
    }
}
long long query(long long p)
{
    long long res = 0;
    while (p > 0)
    {
        res += ta[p], p -= lowbit(p);
    }
    return res;
}
void editnx(long long p, long long k) // 维护每个逆序对的贡献 及 每个逆序对数量的次数
{
    if (p > 0)
    {
        long long ex = p;
        while (p <= n)
        {
            tnx[p] += ex * k, cnx[p] += k, p += lowbit(p);
        }
    }
}
pair<long long, long long> querynx(long long p)
{
    pair<long long, long long> res = make_pair(0, 0);
    while (p > 0)
    {
        res.first += tnx[p], res.second += cnx[p], p -= lowbit(p);
    }
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    sz = all.size();
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
        edit(a[i]);
        nx[i] = i - query(a[i]); // 第i个数前方比它大的数的个数
        editnx(nx[i], 1);
    }
    while (m--)
    {
        long long op, k;
        cin >> op >> k;
        if (op == 1)
        {
            swap(a[k], a[k + 1]), swap(nx[k], nx[k + 1]);
            if (a[k] < a[k + 1])
            {
                editnx(nx[k], -1), editnx(nx[k] - 1, 1);
                nx[k]--;
            }
            else if (a[k] > a[k + 1])
            {
                editnx(nx[k + 1], -1), editnx(nx[k + 1] + 1, 1);
                nx[k + 1]++;
            }
        }
        else
        {
            if (k >= n)
            {
                cout << "0\n";
            }
            else // 逆序对数量大于k才有贡献
            {
                pair<long long, long long> a1 = querynx(n), a2 = querynx(k);
                cout << (a1.first - a2.first) - k * (a1.second - a2.second) << "\n";
            }
        }
    }
    return 0;
}
// TAG: 树状数组 线段树 逆序对