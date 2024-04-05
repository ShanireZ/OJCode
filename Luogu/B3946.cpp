#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int cnt[15], n;
int main()
{
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        if (c != '2' && c != '0' && c != '1' && c != '4')
        {
            cout << "No\n";
            return 0;
        }
        cnt[c - '0']++;
    }
    if (cnt[2] == cnt[0] && cnt[2] == cnt[1] && cnt[2] == cnt[4])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}