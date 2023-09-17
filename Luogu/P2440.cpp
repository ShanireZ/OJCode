#include <algorithm>
#include <iostream>
using namespace std;
long long w[100005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    int L = 1, R = 100000000;
    while (L <= R)
    {
        int mid = (L + R) / 2, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += w[i] / mid;
        }
        cnt >= k ? L = mid + 1 : R = mid - 1;
    }
    cout << L - 1 << endl;
    return 0;
}