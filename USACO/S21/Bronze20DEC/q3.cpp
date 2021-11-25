#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int x, y, eat, tp, id; //tp=0-->north  tp=1-->east
};
Node cow[100];
bool cmp(Node a, Node b)
{
    if (a.tp == b.tp)
    {
        if (a.tp == 0)
        {
            return a.x < b.x;
        }
        else
        {
            return a.y < b.y;
        }
    }
    return a.tp < b.tp;
}
bool cmpid(Node a, Node b)
{
    return a.id < b.id;
}
int main()
{
    int n, cntn = 0, cnte = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char op;
        int x, y;
        cin >> op >> cow[i].x >> cow[i].y;
        cow[i].id = i;
        if (op == 'N')
        {
            cow[i].tp = 0;
            cntn++;
        }
        else
        {
            cow[i].tp = 1;
            cnte++;
        }
    }
    sort(cow + 1, cow + 1 + n, cmp);
    for (int i = 1; i <= cntn; i++) //向北的为i
    {
        for (int j = cntn + 1; j <= n; j++) //向东的为j
        {
            if (cow[i].eat != 0 || cow[j].eat != 0)
            {
                continue;
            }
            if (cow[i].x >= cow[j].x && cow[i].y <= cow[j].y) //向北的i在右下 向东的j在左上
            {
                if (cow[i].x - cow[j].x > cow[j].y - cow[i].y)
                {
                    cow[j].eat = cow[i].x - cow[j].x;
                }
                else if (cow[i].x - cow[j].x < cow[j].y - cow[i].y)
                {
                    cow[i].eat = cow[j].y - cow[i].y;
                    break;
                }
            }
        }
    }
    sort(cow + 1, cow + 1 + n, cmpid);
    for (int i = 1; i <= n; i++)
    {
        if (cow[i].eat)
        {
            cout << cow[i].eat << endl;
        }
        else
        {
            cout << "Infinity" << endl;
        }
    }
    return 0;
}