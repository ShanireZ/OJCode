#include <algorithm>
#include <iostream>
using namespace std;
long long s[10005];
int main()
{
    int n;
    cin >> n;
    long long c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c1 += s[i] * x;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c2 += s[i] * x;
    }
    if(c1 == c2)
    {
        cout << "same" << endl;
    }
    else if(c1 > c2)
    {
        cout << "ke" << endl;
    }
    else
    {
        cout << "do" << endl;
    }
    return 0;
}