#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Block
{
    int v, pre, nxt, p;
    vector<int> all;
} block[200005];
int head = 1, pos;
vector<int> opt[200005];
int main()
{
    int n;
    scanf("%d", &n);
    block[0].v = -1;
    int minsz = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        if (block[pos].v == num)
        {
            block[pos].all.push_back(i);
        }
        else
        {
            if (pos != 0)
            {
                minsz = min(minsz, int(block[pos].all.size()));
            }
            pos++;
            block[pos].pre = pos - 1;
            block[pos - 1].nxt = pos;
            block[pos].v = num;
            block[pos].all.push_back(i);
        }
    }
    minsz = min(minsz, int(block[pos].all.size()));
    int t = 1;
    while (head)
    {
        int r = minsz;
        minsz = 1e9;
        int type = block[head].v, totsz = 0;
        for (int i = head; i != 0; i = block[i].nxt)
        {
            if (block[i].v != block[block[i].pre].v)
            {
                for (int j = 0; j < r; j++)
                {
                    if (block[i].p == block[i].all.size())
                    {
                        i = block[i].nxt;
                    }
                    opt[t + j].push_back(block[i].all[block[i].p]);
                    block[i].p++;
                }
            }
        }
        for (int i = head; i != 0; i = block[i].nxt)
        {
            if (block[i].p == block[i].all.size())
            {
                block[block[i].pre].nxt = block[i].nxt;
                block[block[i].nxt].pre = block[i].pre;
                if (i == head)
                {
                    head = block[i].nxt;
                }
            }
            else if (type == block[i].v)
            {
                totsz += block[i].all.size() - block[i].p;
            }
            else if (type != block[i].v)
            {
                minsz = min(minsz, totsz);
                type = block[i].v;
                totsz = block[i].all.size() - block[i].p;
            }
        }
        minsz = min(minsz, totsz);
        t += r;
    }
    for (int i = 1; i < t; i++)
    {
        for (int j = 0; j < opt[i].size(); j++)
        {
            printf("%d ", opt[i][j]);
        }
        printf("\n");
    }
    return 0;
}