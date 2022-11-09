#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
string a, b;
int main()
{
    int t;
    cin >> t;
    for (int tz = 1; tz <= t; tz++)
    {
        int n, m;
        cin >> n >> m;
        cin >> a >> b;
        transform(a.begin(), a.end(), a.begin(), ::toupper);
        transform(b.begin(), b.end(), b.begin(), ::toupper);
        int pos = 0, cnt = 0;
        pos = b.find(a, pos);
        while (pos != string::npos)
        {
            cnt++;
            pos = b.find(a, pos + 1);
        }
        cout << cnt << endl;
    }
    return 0;
}