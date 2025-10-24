#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<string, int> mp;
int n, k, s, pos;
string str, now, ids[3005];
int main()
{
    cin >> n >> k >> s;
    for (int i = 1; i <= k; i++)
    {
        cin >> str;
        mp[str] = ++pos;
        ids[pos] = str;
    }
    cin >> str;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (mp.count(now + str[i]) == 0)
        {
            cout << mp[now] << " ";
            mp[now + str[i]] = ++pos;
            ids[pos] = now + str[i];
            now = str[i];
        }
        else
        {
            now += str[i];
        }
    }
    cout << mp[now] << endl;
    cout << pos << endl;
    for(int i = 1; i <= pos; i++)
    {
        cout << ids[i] << endl;
    }
    return 0;
}