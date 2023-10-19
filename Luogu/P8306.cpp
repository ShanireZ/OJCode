#include <iostream>
#include <string>
using namespace std;
string s;
int pos, cnt[3000005], chs[3000005][65]; // 0-9:0~9 10~35:a~z 36~61:A~Z
void make()
{
    int now = 0;
    for (char ch : s)
    {
        int cid = -1;
        if (ch >= '0' && ch <= '9')
        {
            cid = ch - '0';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            cid = ch - 'a' + 10;
        }
        else
        {
            cid = ch - 'A' + 36;
        }
        if (chs[now][cid] == 0)
        {
            chs[now][cid] = ++pos;
        }
        now = chs[now][cid], cnt[now]++;
    }
}
int find()
{
    int now = 0;
    for (char ch : s)
    {
        int cid = -1;
        if (ch >= '0' && ch <= '9')
        {
            cid = ch - '0';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            cid = ch - 'a' + 10;
        }
        else
        {
            cid = ch - 'A' + 36;
        }
        now = chs[now][cid];
        if (now == 0)
        {
            break;
        }
    }
    return cnt[now];
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> s;
            make();
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> s;
            cout << find() << endl;
        }
        for (int i = 0; i <= pos; i++)
        {
            cnt[i] = 0;
            for (int j = 0; j < 62; j++)
            {
                chs[i][j] = 0;
            }
        }
        pos = 0;
    }
    return 0;
}