#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<string, int> t;
string words[10005], s;
int n, ans = 1, base = 233, mod = 1e7 + 19;
long long hsh[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        char lst = '1';
        for (char ch : s)
        {
            if (ch == lst)
            {
                continue;
            }
            words[i] += ch, lst = ch;
        }
        t[words[i]]++;
        if (t[words[i]] > t[words[ans]])
        {
            ans = i;
        }
    }
    cout << words[ans] << endl;
    return 0;
}