#include <iostream>
using namespace std;
int pos[300005];
long long h[300005];
int main()
{
    int n, head = 1, last = 0;
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        while (last >= head && h[i] > h[pos[last]])
        {
            ans += i - pos[last] + 1;
            last--;
        }
        if (last >= head)
        {
            ans += i - pos[last] + 1;
        }
        pos[++last] = i;
    }
    cout << ans << endl;
    return 0;
}