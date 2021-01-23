#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string st;
string all[25];
int n, len, max_len;
int usd[25];
void dfs(string a)
{
    for (int i = 1; i < a.size(); i++) //取出个数
    {
        string ck1 = a.substr(a.size() - i, i);
        for (int j = 1; j <= n; j++) //目标字符串
        {
            if (all[j].size() > i && usd[j] < 2)
            {
                string ck2 = all[j].substr(0, i);
                if (ck1 == ck2)
                {
                    len += all[j].size() - i;
                    usd[j]++;
                    dfs(all[j]);
                    len -= all[j].size() - i;
                    usd[j]--;
                }
            }
        }
    }
    max_len = max(len, max_len);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    cin >> st;
    st.insert(0, " ");
    len = 1;
    dfs(st);
    cout << max_len;
    return 0;
}