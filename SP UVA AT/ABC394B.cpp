#include <algorithm>
#include <iostream>
using namespace std;
string s[100];
bool cmp(string a, string b)
{
    return a.size() < b.size();
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << s[i];
    }
    return 0;
}