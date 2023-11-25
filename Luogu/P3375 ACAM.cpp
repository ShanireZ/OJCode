#include <iostream>
#include <queue>
#include <string>
using namespace std;
string s1, s2;
int trie[1000005][30], fail[1000005], root, pos;
queue<int> q;
void maket()
{
    int now = root;
    for (char c : s2)
    {
        int id = c - 'A';
        if (!trie[now][id])
        {
            trie[now][id] = ++pos;
        }
        now = trie[now][id];
    }
}
int findpos(int now, int x)
{
    while (now != 0 && trie[now][x] == 0)
    {
        now = fail[now];
    }
    return now == 0 ? root : trie[now][x];
}
void makef()
{
    q.push(root);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = trie[now][i];
            int f = findpos(fail[now], i);
            if (nxt == 0)
            {
                trie[now][i] = f;
            }
            else
            {
                fail[nxt] = f, q.push(nxt);
            }
        }
    }
}
int main()
{
    cin >> s1 >> s2;
    int p = s1.find(s2);
    while (p != string::npos)
    {
        cout << p + 1 << endl;
        p = s1.find(s2, p + 1);
    }
    root = ++pos;
    maket(), makef();
    for (int i = 2; i <= pos; i++)
    {
        cout << fail[i] - 1 << " ";
    }
    return 0;
}