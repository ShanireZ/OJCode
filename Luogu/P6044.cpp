#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Seg
{
    int l, r, id;
    bool operator<(const Seg &oth) const
    {
        return r > oth.r;
    }
};
Seg s[1000005];
priority_queue<Seg> q;
vector<int> res;
bool cmpL(Seg a, Seg b)
{
    return a.l < b.l;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].l >> s[i].r;
        s[i].id = i;
    }
    sort(s + 1, s + n + 1, cmpL); // 按l排序
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) // l此时从小到大入队
    {
        q.push(s[i]);
        if ((int)q.size() > k) // r小的出队
        {
            q.pop();
        }
        if ((int)q.size() == k && r - l < q.top().r - s[i].l) // 最小的r到最大的l
        {
            l = s[i].l, r = q.top().r;
        }
    }
    cout << r - l << endl;
    for (int i = 1; i <= n; i++)
    {
        if (s[i].l <= l && s[i].r >= r)
        {
            res.emplace_back(s[i].id);
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < k; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}