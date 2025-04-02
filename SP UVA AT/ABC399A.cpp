#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int n, cnt;
int main()
{
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        cnt += (s[i] != t[i]);
    }
    cout << cnt << endl;
    return 0;
}