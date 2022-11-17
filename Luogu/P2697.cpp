#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<int, int> fst;
int main()
{
    string s;
    cin >> s;
    int totg = 0, totr = 0, ans = 0;
    fst[0] = 0;
    for (int i = 0; i < int(s.size()); i++)
    {
        (s[i] == 'G') ? totg++ : totr++;
        int x = totg - totr;
        if (fst.count(x) != 0)
        {
            ans = max(ans, i + 1 - fst[x]);
        }
        else
        {
            fst[x] = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}