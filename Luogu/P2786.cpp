#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
map<string, int> words;
int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        string str;
        int s;
        cin >> str >> s;
        words[str] = s;
    }
    int ans = 0;
    string str;
    char ch = getchar();
    while (ch != EOF)
    {
        if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            str += ch;
        }
        else
        {
            ans += words[str];
            str.clear();
        }
        ch = getchar();
    }
    cout << ans % p;
    return 0;
}