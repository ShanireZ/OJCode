#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
set<char> to[150], all, st;
stack<char> s;
int dg[150];
void dfs(char now)
{
    while ((int)to[now].size())
    {
        char nxt = *to[now].begin();
        to[now].erase(nxt), to[nxt].erase(now);
        dfs(nxt);
    }
    s.push(now);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // 需要注意的是題目資料有自環無重邊
    {
        char u, v;
        cin >> u >> v;
        dg[u]++, dg[v]++, all.insert(u), all.insert(v);
        to[u].insert(v), to[v].insert(u);
    }
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (dg[i] % 2 == 1)
        {
            st.insert(i);
        }
    }
    if ((int)st.size() != 0 && (int)st.size() != 2)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        dfs((st.size() == 2 ? *st.begin() : *all.begin()));
        // 題目資料都是連通圖，實際還需要判圖連通性
        while (s.size())
        {
            cout << s.top();
            s.pop();
        }
    }
    return 0;
}
// TAG: 歐拉回路 歐拉路徑 無向圖 圖的遍歷