#include <iostream>
#include <algorithm>
using namespace std;
int hang[1000005];
int lie[1000005];
int main()
{
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> hang[i] >> lie[i];
    }
    sort(hang + 1, hang + 1 + k);
    sort(lie + 1, lie + 1 + k);
    long long totx = unique(hang + 1, hang + 1 + k) - (hang + 1);
    long long toty = unique(lie + 1, lie + 1 + k) - (lie + 1);
    long long ans = (totx + toty) * n - totx * toty;
    cout << ans;
    return 0;
}