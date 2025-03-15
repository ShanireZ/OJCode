#include <cstring>
#include <iostream>
using namespace std;
long long ts[200005], cf[200005], v[200005], n, m;
void edit(int x)
{
    while (x <= m)
    {
        ts[x]++;
        x += (x & -x);
    }
}
long long query(int x)
{
    long long res = 0;
    while (x)
    {
        res += ts[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    // v[p]表示v[i]前方数
    // 如果v[p]>v[i],则在[0, m-v[p])和[m-v[i], m)范围内会出现逆序对
    // 如果v[p]<v[i],则在[m-v[i], m-v[p])范围内会出现逆序对
    // 如果v[p]=v[i],则不产生逆序对
    // 对区间进行差分,最后O(m)对差分数组求前缀即可
    // 如果查看每对(p,i),则此部分复杂度为O(n^2)
    // 考虑优化,每个固定的i,只需要负责将自己负责的部分差分修改*次数即可,正逆各一遍即可又代表i又代表p
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        // 因为树状数组无法维护0,所以树状数组中1~m出现的次数表示0~m-1出现的次数
        long long sum1 = query(v[i]);             // 前方比v[i]小的个数
        long long sum2 = i - 1 - query(v[i] + 1); // 前方比v[i]大的个数
        cf[m - v[i]] += sum1;
        cf[m - v[i]] += sum2, cf[m] -= sum2;
        edit(v[i] + 1);
    }
    memset(ts, 0, sizeof(ts));
    for (int i = n; i >= 1; i--)
    {
        long long sum1 = query(v[i]);             // 后方比v[i]小的个数
        long long sum2 = n - i - query(v[i] + 1); // 后方比v[i]大的个数
        cf[0] += sum1, cf[m - v[i]] -= sum1;
        cf[m - v[i]] -= sum2;
        edit(v[i] + 1);
    }
    cout << cf[0] << '\n';
    for (int i = 1; i < m; i++)
    {
        cf[i] += cf[i - 1];
        cout << cf[i] << '\n';
    }
    return 0;
}