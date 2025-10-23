#include <algorithm>
#include <iostream>
using namespace std;
int n, a[100005], b[100005];
string s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    cin >> s;
    int p = max((int)s.rfind('a'), (int)s.rfind('b'));
    int np = p + 2, val = 0;
    while (s[np] >= '0' && s[np] <= '9')
    {
        val = val * 10 + s[np] - '0';
        np++;
    }
    val = (s[p] == 'a' ? a[val] : b[val]);
    while (p)
    {
        p -= 2;
        val = (s[p] == 'a' ? a[val] : b[val]);
    }
    cout << val << endl;
    return 0;
}