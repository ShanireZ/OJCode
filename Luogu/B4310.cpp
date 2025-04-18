#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int n, k, sum, len = -1, st, ed, a[100005];
unordered_map<int, int> fst;
int main()
{
    cin >> n >> k;
    fst[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum = (sum + a[i]) % k;
        if (sum != 0 && fst[sum] == 0)
        {
            fst[sum] = i;
        }
        else if (len == i - fst[sum] && st < fst[sum] + 1)
        {
            st = fst[sum] + 1, ed = i;
        }
        else if (len < i - fst[sum])
        {
            len = i - fst[sum];
            st = fst[sum] + 1, ed = i;
        }
    }
    cout << len << endl;
    if (len > 0)
    {
        for (int i = st; i <= ed; i++)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}