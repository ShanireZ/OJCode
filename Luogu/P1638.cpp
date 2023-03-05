#include <iostream>
using namespace std;
int pt[1000005], t[2005];
int main()
{
    int n, m;
    cin >> n >> m;
    int minl = n, a = 1, b = n, cnt = 0, pos = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pt[i] = x, t[x]++;
        cnt += (t[x] == 1);
        while (t[pt[pos]] > 1)
        {
            t[pt[pos]]--;
            pos++;
        }
        if (cnt == m && i - pos + 1 < minl)
        {
            minl = i - pos + 1, a = pos, b = i;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}