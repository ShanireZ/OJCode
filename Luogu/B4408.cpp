#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;
map<string, int> pts, dcts;
struct Info
{
    string pt, dct;
    int zl, gh, vis;
};
Info info[1500];
struct Node
{
    string pt;
    int zl, gh;
    bool operator<(const Node &oth) const
    {
        if (zl == oth.zl)
        {
            return gh > oth.gh;
        }
        return zl > oth.zl;
    }
};
priority_queue<Node> nor[1500];
queue<string> lt[1500];
int T, pos, dpos;
int main()
{
    cin >> T;
    while (T--)
    {
        int h, m, zh, zm;
        string op, pt, dct;
        cin >> h >> m >> op;
        if (op == "appointment")
        {
            cin >> pt >> dct >> zh >> zm;
            if (pts[pt] == 0)
            {
                pts[pt] = ++pos;
            }
            if (dcts[dct] == 0)
            {
                dcts[dct] = ++dpos;
            }
            info[pos] = Info{pt, dct, zh * 60 + zm, h * 60 + m, 0};
        }
        else if (op == "register")
        {
            cin >> pt;
            int id = pts[pt], did = dcts[info[id].dct];
            if (id == 0 || info[id].vis || info[id].zl - (h * 60 + m) > 60)
            {
                cout << "Fail" << endl;
            }
            else
            {
                cout << "Success" << endl;
                info[id].vis = 1;
                if (info[id].zl < h * 60 + m)
                {
                    lt[did].push(pt);
                }
                else
                {
                    nor[did].push(Node{pt, info[id].zl, info[id].gh});
                }
            }
        }
        else
        {
            cin >> dct;
            int did = dcts[dct];
            if (nor[did].size())
            {
                for (int i = 0; i < (int)nor[did].top().pt.size(); i++)
                {
                    cout << (i == 0 || i == (int)nor[did].top().pt.size() - 1 ? nor[did].top().pt[i] : '*');
                }
                cout << endl;
                nor[did].pop();
            }
            else if (lt[did].size())
            {
                for (int i = 0; i < (int)lt[did].front().size(); i++)
                {
                    cout << (i == 0 || i == (int)lt[did].front().size() - 1 ? lt[did].front()[i] : '*');
                }
                cout << endl;
                lt[did].pop();
            }
            else
            {
                cout << "No patient" << endl;
            }
        }
    }
    return 0;
}