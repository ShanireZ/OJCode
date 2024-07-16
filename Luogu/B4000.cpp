#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    s += k;
    m += s / 60, s %= 60;
    h += m / 60, m %= 60;
    cout << h << " " << m << " " << s << endl;
    return 0;
}