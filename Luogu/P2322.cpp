#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int p, state, step;
};
int n, root = 1, pos = 1, cpos, ed[605], fail[605], from[605][4100][2], len[605][4100], trie[605][26];
char chs[605];
string s;
queue<int> q;
queue<Node> qp;
void init(int i)
{
    int now = root;
    for (char ch : s)
    {
        int x = ch - 'A';
        if (trie[now][x] == 0)
        {
            trie[now][x] = ++pos;
            chs[pos] = ch;
        }
        now = trie[now][x];
    }
    ed[now] |= (1 << i);
}
int findpos(int now, int x)
{
    while (now != 0 && trie[now][x] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? root : trie[now][x];
}
void makefail()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop(), ed[now] |= ed[fail[now]];
        for (int i = 0; i < 26; i++)
        {
            int f = findpos(fail[now], i);
            if (trie[now][i] == 0)
            {
                trie[now][i] = f;
                continue;
            }
            q.push(trie[now][i]), fail[trie[now][i]] = f;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        init(i);
    }
    makefail();
    memset(len, 0x3f, sizeof(len));
    qp.push(Node{root, 0, 0}), len[root][0] = 0;
    while (qp.size())
    {
        int now = qp.front().p, state = qp.front().state, step = qp.front().step;
        qp.pop();
        if (len[now][state] != step)
        {
            continue;
        }
        for (int i = 0; i < 26; i++)
        {
            int nxt = trie[now][i];
            int nstate = state | ed[nxt];
            if (len[nxt][nstate] > step + 1)
            {
                len[nxt][nstate] = step + 1;
                from[nxt][nstate][0] = now, from[nxt][nstate][1] = state;
                qp.push(Node{nxt, nstate, step + 1});
            }
        }
        if (state == (1 << n) - 1)
        {
            s.clear();
            while (now)
            {
                s += chs[now];
                int x = now;
                now = from[x][state][0], state = from[x][state][1];
            }
            reverse(s.begin(), s.end());
            s.erase(s.begin());
            cout << s << endl;
            break;
        }
    }
    return 0;
}