#include <iostream>
#include <string>
#include <queue>
using namespace std;
string str, tmp;
int n, pos, root, spos;
struct Node
{
    char v;
    int fa, ed, fail;
    int ch[26];
};
Node ns[100005];
int pt[100005];
char ans[100005];
queue<int> q;
int newnode(int now, char ch)
{
    if (ns[now].ch[ch - 'a'] == 0)
    {
        ns[now].ch[ch - 'a'] = ++pos;
        ns[pos].v = ch;
        ns[pos].fa = now;
    }
    return ns[now].ch[ch - 'a'];
}
int findp(int now, char ch)
{
    while (ns[now].ch[ch - 'a'] == 0)
    {
        now = ns[now].fail;
        if (now == 0)
        {
            break;
        }
    }
    now = ns[now].ch[ch - 'a'];
    if (now == 0)
    {
        now = root;
    }
    return now;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> str >> n;
    root = ++pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        int now = root;
        for (int j = 0; j < tmp.size(); j++)
        {
            now = newnode(now, tmp[j]);
        }
        ns[now].ed = tmp.size();
    }
    for (int i = 0; i < 26; i++)
    {
        int id = ns[root].ch[i];
        if (id)
        {
            ns[id].fail = root;
            q.push(id);
        }
    }

    while (q.size())
    {
        int from = q.front();
        for (int i = 0; i < 26; i++)
        {
            //todo 优化fail和ch合并,使ch数组可以直接定位到目标点
            int to = ns[from].ch[i];
            if (to) //目标子字符存在
            {
                q.push(to);
                int failp = findp(ns[from].fail, 'a' + i);
                ns[to].fail = failp;
            }
            else //目标子字符不存在
            {
                ns[from].ch[i] = findp(ns[from].fail, 'a' + i);
            }
        }
        q.pop();
    }
    //todo 版本控制，如果删除了一个字符串就回退到最后一个未删除字符的版本
    pt[0] = root; //第i个字符的起始搜索位置 上个元素在树中的位置
    for (int i = 0; i < str.size(); i++)
    {
        int id = findp(pt[spos], str[i]);
        if (ns[id].ed)
        {
            spos = spos - ns[id].ed + 1;
            continue;
        }
        pt[spos + 1] = id;
        ans[spos] = str[i];
        spos++;
    }
    for (int i = 0; i < spos; i++)
    {
        cout << ans[i];
    }
    return 0;
}