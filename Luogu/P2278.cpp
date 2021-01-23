#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int id, st, dur, rank;
};
struct cmp
{
    bool operator()(Node a, Node b)
    {
        if (a.rank == b.rank)
        {
            return a.st > b.st;
        }
        return a.rank < b.rank;
    }
};
priority_queue<Node, vector<Node>, cmp> cpu;
int main()
{
    ios::sync_with_stdio(false);
    Node tmp;
    cin >> tmp.id >> tmp.st >> tmp.dur >> tmp.rank;
    cpu.push(tmp);
    int st = tmp.st;
    while (cin >> tmp.id >> tmp.st >> tmp.dur >> tmp.rank)
    {
        Node top = cpu.top();
        while (st + top.dur <= tmp.st)
        {
            cout << top.id << " " << st + top.dur << endl;
            cpu.pop();
            st = st + top.dur;
            top = cpu.top();
            if (cpu.size() == 0)
            {
                st = tmp.st;
                break;
            }
        }
        if (cpu.size() && top.rank < tmp.rank)
        {
            int run = tmp.st - st;
            top.dur -= run;
            cpu.pop();
            cpu.push(top);
            st = tmp.st;
        }
        cpu.push(tmp);
    }
    while (cpu.size())
    {
        Node top = cpu.top();
        cout << top.id << " " << st + top.dur << endl;
        st += top.dur;
        cpu.pop();
    }
    return 0;
}