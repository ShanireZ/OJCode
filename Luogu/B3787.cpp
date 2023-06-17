#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h1, m1, s1, ss1, h2, m2, s2, ss2;
    char ch;
    cin >> h1 >> ch >> m1 >> ch >> s1 >> ch >> ss1;
    cin >> h2 >> ch >> m2 >> ch >> s2 >> ch >> ss2;
    int ans = (h2 - h1) * 60 * 60 * 100 + (m2 - m1) * 60 * 100 + (s2 - s1) * 100 + (ss2 - ss1);
    cout << ans << "\n";
    return 0;
}