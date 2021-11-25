#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, times = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    while (a != b)
    {
        int pos = 0;
        while (a[pos] == b[pos])
        {
            pos++;
        }
        while (a[pos] != b[pos] && pos < n)
        {
            pos++;
        }
        times++;
        if (pos == n)
        {
            break;
        }
        a = a.substr(pos);
        b = b.substr(pos);
    }
    cout << times;
    return 0;
}