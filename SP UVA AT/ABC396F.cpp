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
    // v[p]表示v[i]前方數
    // 如果v[p]>v[i],則在[0, m-v[p])和[m-v[i], m)範圍內會出現逆序對
    // 如果v[p]<v[i],則在[m-v[i], m-v[p])範圍內會出現逆序對
    // 如果v[p]=v[i],則不產生逆序對
    // 對區間進行差分,最後O(m)對差分陣列求前綴即可
    // 如果查看每對(p,i),則此部分複雜度為O(n^2)
    // 考慮優化,每個固定的i,只需要負責將自己負責的部分差分修改*次數即可,正逆各一遍即可又代表i又代表p
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        // 因為樹狀陣列無法維護0,所以樹狀陣列中1~m出現的次數表示0~m-1出現的次數
        long long sum1 = query(v[i]);             // 前方比v[i]小的個數
        long long sum2 = i - 1 - query(v[i] + 1); // 前方比v[i]大的個數
        cf[m - v[i]] += sum1;
        cf[m - v[i]] += sum2, cf[m] -= sum2;
        edit(v[i] + 1);
    }
    memset(ts, 0, sizeof(ts));
    for (int i = n; i >= 1; i--)
    {
        long long sum1 = query(v[i]);             // 後方比v[i]小的個數
        long long sum2 = n - i - query(v[i] + 1); // 後方比v[i]大的個數
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