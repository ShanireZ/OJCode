#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Node
{
    int fa, fail, ch[26], id, tag, ind;
    char v;
};
Node ns[1000005];
int pos, root, n, ts[205], real[205];
string str;
queue<int> q;
int newnode(int now, char ch) //新点定位
{
    if (ns[now].ch[ch - 'a'] == 0)
    {
        ns[now].ch[ch - 'a'] = ++pos;
        ns[pos].v = ch;
        ns[pos].fa = now;
    }
    return ns[now].ch[ch - 'a'];
}
int findp(int now, char ch) //丛now的儿子开始查找ch的位置
{
    while (ns[now].ch[ch - 'a'] == 0)
    {
        now = ns[now].fail;
        if (now == 0)
        {
            break;
        }
    }
    if (now == 0)
    {
        return root;
    }
    return ns[now].ch[ch - 'a'];
}
int main()
{
    cin >> n;
    root = ++pos;
    for (int i = 1; i <= n; i++) //建立trie
    {
        cin >> str;
        int now = root;
        for (int j = 0; j < str.size(); j++)
        {
            now = newnode(now, str[j]);
            ns[now].tag++;
        }
        if (ns[now].id == 0)
        {
            ns[now].id = i;
        }
        real[i] = ns[now].id;
    }
    for (int i = 0; i < 26; i++) //构建trie每个节点fail指针
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
            int to = ns[from].ch[i];
            if (to)
            {
                q.push(to);
                ns[to].fail = findp(ns[from].fail, 'a' + i);
                ns[ns[to].fail].ind++;
            }
            else
            {
                ns[from].ch[i] = findp(ns[from].fail, 'a' + i);
            }
        }
        q.pop();
    }
    for (int i = 2; i <= pos; i++)
    {
        if (ns[i].ind == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int from = q.front();
        int to = ns[from].fail;
        ns[to].tag += ns[from].tag; //传递次数给to
        if (ns[from].id)            //统计单词出现次数
        {
            ts[ns[from].id] += ns[from].tag;
        }
        ns[to].ind--;
        if (ns[to].ind == 0)
        {
            q.push(to);
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ts[real[i]] << endl;
    }
    return 0;
}