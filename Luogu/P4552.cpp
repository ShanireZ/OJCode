#include <iostream>
using namespace std;
int main()
{
    int n;
    long long pre, now, totz = 0, totf = 0;
    cin >> n >> pre;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        long long x = now - pre;
        (x > 0) ? totz += x : totf -= x;
        pre = now;
    }
    cout << max(totz, totf) << endl;
    cout << abs(totz - totf) + 1 << endl;
    return 0;
}