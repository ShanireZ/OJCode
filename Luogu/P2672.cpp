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
//! suma為a的1-i前綴和 maxd為1-i的s最大值 maxback為i-n的貢獻最大值
//! 何為貢獻？ 假設第i個元素不選而選其後第j個元素更優
//! 那麼必然 (sj - s) * 2 + (aj - a) 更優
//! s a都是每個情況下的固定值 所以2 * sj + aj 必定得是最優 這個值可以看作貢獻
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
        int ans = suma[i] + maxd[i] * 2; //! 選擇推銷疲勞排名前i個的情況
        //! 放棄推銷疲勞排名第i個 選擇後面的最大貢獻
        //! 為何不用判斷後面的最大貢獻長度 和 前i-1個長度？
        //! 後面的推銷疲勞本來就小 如果後面的長度也比前面的小 那麼max後必然不會更新值
        ans = max(ans, suma[i - 1] + maxback[i + 1]);
        cout << ans << endl;
    }
    return 0;
}