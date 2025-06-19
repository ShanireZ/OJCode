#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string s;
int path[50], p[20], v[20], ex[20], pos, id;
int main()
{
    memset(v, -1, sizeof(v)), v[0] = 0;
    while (cin >> s)
    {
        if (s == "/")
        {
            path[++pos] = 10;
            p[++id] = pos;
            v[id] = 10, ex[id] = 2;
        }
        else if (s.size() == 1)
        {
            path[++pos] = s[0] - '0';
            break;
        }
        else if (s[1] == '/')
        {
            path[++pos] = s[0] - '0';
            path[++pos] = 10 - (s[0] - '0');
            p[++id] = pos;
            v[id] = 10, ex[id] = 1;
        }
        else
        {
            path[++pos] = s[0] - '0';
            path[++pos] = s[1] - '0';
            p[++id] = pos;
            v[id] = path[pos] + path[pos - 1];
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        int now = p[i] + 1;
        while (ex[i] && now <= pos)
        {
            v[i] += path[now];
            now++, ex[i]--;
        }
        if (ex[i])
        {
            v[i] = -1;
        }
    }
    for (int i = 1; i <= 10 && v[i] != -1; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 1; i <= 10 && v[i] != -1; i++)
    {
        v[i] += v[i - 1];
        cout << v[i] << " ";
    }
    return 0;
}