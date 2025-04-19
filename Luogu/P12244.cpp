#include <algorithm>
#include <iostream>
using namespace std;
int l[100005], r[100005], n, t, sum;
int main()
{
    cin >> n >> t >> l[1] >> r[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        int dur = l[i] - r[i - 1];
        if (dur > t)
        {
            sum += dur - t;
        }
    }
    cout << sum << endl;
    return 0;
}