#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string dw[10] = {"B", "KB", "MB", "GB"};
string tp[10] = {"int", "int[]", "long", "long[]", "String"};
long long ans[10], sz[10] = {4, 4, 8, 8, 1}, tot;
string s, opt;
long long query(int id)
{
    long long cnt = 0;
    if (id == 4)
    {
        int pos = s.find("\"");
        while (pos != string::npos)
        {
            int npos = s.find("\"", pos + 1);
            cnt += npos - pos - 1;
            pos = s.find("\"", npos + 1);
        }
    }
    else if (id % 2 == 0)
    {
        int pos = s.find("=");
        while (pos != string::npos)
        {
            cnt++, pos = s.find("=", pos + 1);
        }
    }
    else
    {
        int pos = s.find("[");
        while (pos != string::npos)
        {
            int npos = s.find("]", pos + 1), tmp;
            stringstream ss;
            ss << s.substr(pos + 1, npos - pos - 1);
            ss >> tmp;
            cnt += tmp;
            pos = s.find("[", pos + 1);
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> opt;
        getline(cin, s);
        for (int i = 0; i < 5; i++)
        {
            tot += (opt == tp[i]) * query(i) * sz[i];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        ans[i] = tot % 1024, tot /= 1024;
    }
    for (int i = 3; i >= 0; i--)
    {
        if (ans[i])
        {
            cout << ans[i] << dw[i];
        }
    }
    return 0;
}