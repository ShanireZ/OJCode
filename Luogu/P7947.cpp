#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
int main()
{
    int n, k, p = 2, tot = 0;
    cin >> n >> k;
    while (n > 1)
    {
        while (n % p == 0)
        {
            ans.push_back(p);
            tot += p;
            n /= p;
        }
        p++;
    }
    if (tot > k)
    {
        cout << -1 << endl;
        return 0;
    }
    ans.resize(ans.size() + k - tot, 1);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}