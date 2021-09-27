#include <iostream>
#include <string>
using namespace std;
string ans[105];
int main()
{
    int n, maxt = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name, msg;
        cin >> name >> msg;
        int t = 0, pos = msg.find("sos");
        while (pos != string::npos)
        {
            t++;
            pos = msg.find("sos", pos + 1);
        }
        if (t > maxt)
        {
            maxt = t;
            cnt = 1;
            ans[1] = name;
        }
        else if (t == maxt)
        {
            cnt++;
            ans[cnt] = name;
        }
    }
    for (int i = 1; i <= cnt; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl
         << maxt << endl;
    return 0;
}