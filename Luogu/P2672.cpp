#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int s, a;
};
bool cmp(Node x, Node y)
{
    return x.a > y.a;
}
Node ns[100005];
//! suma为a的1-i前缀和 maxd为1-i的s最大值 maxback为i-n的贡献最大值
//! 何为贡献？ 假设第i个元素不选而选其后第j个元素更优
//! 那么必然 (sj - s) * 2 + (aj - a) 更优
//! s a都是每个情况下的固定值 所以2 * sj + aj 必定得是最优 这个值可以看作贡献
int suma[100005], maxd[100005], maxback[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].s;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].a;
    }
    sort(ns + 1, ns + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        maxd[i] = max(maxd[i - 1], ns[i].s);
        suma[i] = suma[i - 1] + ns[i].a;
    }
    for (int i = n; i >= 1; i--)
    {
        maxback[i] = max(maxback[i + 1], ns[i].s * 2 + ns[i].a);
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = suma[i] + maxd[i] * 2; //! 选择推销疲劳排名前i个的情况
        //! 放弃推销疲劳排名第i个 选择后面的最大贡献
        //! 为何不用判断后面的最大贡献长度 和 前i-1个长度？
        //! 后面的推销疲劳本来就小 如果后面的长度也比前面的小 那么max后必然不会更新值
        ans = max(ans, suma[i - 1] + maxback[i + 1]);
        cout << ans << endl;
    }
    return 0;
}