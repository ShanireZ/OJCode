#include <iostream>
using namespace std;
struct Node
{
    int price, t, check;
};
Node tks[100005];
int main()
{
    int n, front = 1, back = 1, cost = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int type, price, t;
        cin >> type >> price >> t;
        if (type == 0)
        {
            cost += price;
            tks[back].price = price;
            tks[back].t = t;
            back++;
        }
        else
        {
            int trig = 1;
            for (int j = front; j < back; j++)
            {
                if (t - tks[j].t > 45)
                {
                    front = j + 1;
                    continue;
                }
                if (tks[j].price >= price && tks[j].check == 0)
                {
                    trig = 0;
                    tks[j].check = 1;
                    break;
                }
            }
            if (trig)
            {
                cost += price;
            }
        }
    }
    cout << cost << endl;
    return 0;
}