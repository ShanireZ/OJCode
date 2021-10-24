#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Block
{
    int v, pre, nxt, st, ed;
};
Block block[200005];
int read();
int head = 1, pos;
vector<int> opt[200005];
int main()
{
    int n = read();
    block[0].v = -1;
    int minsz = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int num = read();
        if (block[pos].v == num)
        {
            block[pos].ed = i;
        }
        else
        {
            if (pos != 0)
            {
                minsz = min(minsz, block[pos].ed - block[pos].st + 1);
            }
            pos++;
            block[pos].pre = pos - 1;
            block[pos - 1].nxt = pos;
            block[pos].v = num;
            block[pos].st = block[pos].ed = i;
        }
    }
    minsz = min(minsz, block[pos].ed - block[pos].st + 1);
    int t = 1;
    while (head)
    {
        int r = minsz;
        minsz = 1e9; 
        for (int i = head; i != 0; i = block[i].nxt) //组果篮
        {
            if (block[i].v != block[block[i].pre].v)
            {
                for (int j = 0; j < r; j++)
                {
                    if (block[i].st > block[i].ed)
                    {
                        i = block[i].nxt;
                    }
                    opt[t + j].push_back(block[i].st);
                    block[i].st++;
                }
            }
        }
        int type = block[head].v, totsz = 0;
        for (int i = head; i != 0; i = block[i].nxt) //跳空块
        {
            if (block[i].st > block[i].ed)
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
                totsz += block[i].ed - block[i].st + 1;
            }
            else if (type != block[i].v)
            {
                minsz = min(minsz, totsz);
                type = block[i].v;
                totsz = block[i].ed - block[i].st + 1;
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
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}